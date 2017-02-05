#include <SDKDDKVer.h>
#include "CSystem.h"

double CSystem::GetCPUSpeedGHz(){
	unsigned long int       ticks;          //���Ǵ�ż�ʱ���������Ź̶�ʱ����ֵ
	unsigned long int       stock0, stock1; //������̶�ʱ�̵�CPU����ʱ��ֵ��ֵ�ĺ���Ϊ����
	unsigned long int       cycles;         //�������ʱ��ֵ֮��ù̶�ʱ�εļ���ֵ 
	unsigned long int       freq[5] = {0,0,0,0,0}; //���Ƶ�ʣ�Ϊ����߾��ȣ����������ڵĲ��5��Ƶ�ʵ�ƽ��ֵ
	unsigned long int       nums = 0;       //ѭ������
	unsigned long int       total = 0;      //���Ƶ��֮��
	LARGE_INTEGER       t0,t1;
	LARGE_INTEGER       countfreq;
	//���ظ߾��ȵļ���Ƶ�ʣ���ÿ����ٴ�;
	if (!QueryPerformanceFrequency( &countfreq ) )
	{
		return 0.0f;
	}
	//�����ض����̵����ȼ�;
	DWORD priority_class = GetPriorityClass(GetCurrentProcess());
	//�����ض��̵߳����ȼ�;
	int   thread_priority = GetThreadPriority(GetCurrentThread());
	//����ǰ�������ʵʱ����;
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	//�趨�߳����ȼ�;
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
	do
	{
		nums++;
		freq[4] = freq[3];
		freq[3] = freq[2];
		freq[2] = freq[1];
		freq[1] = freq[0];
		//���ظ߾��ȼ�����ֵ;
		QueryPerformanceCounter(&t0);
		t1.LowPart = t0.LowPart;
		t1.HighPart = t0.HighPart;
		//����е�50�ͺ�����ͬ����е�1000��һ������ֵ����������ǿ���ʱ����������
		//����������ֵ��ʵ�����ʱ������
		while ( (unsigned long int)t1.LowPart - (unsigned long int)t0.LowPart<10)
		{
			QueryPerformanceCounter(&t1);
		}
		_asm
		{
			rdtsc  //������ȡCPU������ʱ�ӣ��䷵��ֵ�Ǹ�64λ����������32��EDX����32��EAX��
				mov stock0, EAX //��λ�����ڶ���ʱ�����ǲ����б仯�ģ�����������Ա�
		}
		t0.LowPart = t1.LowPart;        // ���ó�ʼʱ��
		t0.HighPart = t1.HighPart;
		while ((unsigned long int)t1.LowPart-(unsigned long int)t0.LowPart<1000 )
		{
			QueryPerformanceCounter(&t1);
		}
		_asm
		{
			rdtsc
				mov  stock1, EAX
		}
		cycles = stock1 - stock0;
		ticks = (unsigned long int) t1.LowPart - (unsigned long int) t0.LowPart;
		ticks = ticks * 1000000;
		ticks = ticks / countfreq.LowPart;
		if ( ticks % countfreq.LowPart > countfreq.LowPart/2 )
		{
			ticks++;            // ʹ��������
		}
		freq[0] = cycles / ticks;    // ���Ƶ�ʣ���λ��MHz
		if ( cycles%ticks > ticks/2 )
		{
			freq[0]++;             // ʹ��������
		}
		total = (freq[0] + freq[1] + freq[2] + freq[3] + freq[4]);
	} while ((nums < 5 ) || (nums < 100) && ( (abs(5 * (long)freq[0] - (long)total) < 5)
		|| (abs(5 * (long)freq[1]-(long)total) < 5) || (abs(5 * (long)freq[2] - (long)total) < 5)
		|| (abs(5 * (long)freq[3]-(long)total) < 5) || (abs(5 * (long)freq[4] - (long)total) < 5)
		));
	//����ѭ������ȷ��ѭ��������5�Σ��ڴ���5�κ�ȷ���ﵽһ���ľ��Ⱥ��˳�
	if ( total/5  !=  ( total + 1 )/5 )
	{
		total ++;               // ʹ��������
	}
	// �ָ����̼��̵߳����ȼ���;
	SetPriorityClass(GetCurrentProcess(), priority_class);
	SetThreadPriority(GetCurrentThread(), thread_priority);
	return double(total) / 5.0 / 1000.0;
}

CRect CSystem::GetTaskbarRect(){
	HWND h = ::FindWindow("Shell_TrayWnd","");
	RECT r;
	::GetWindowRect(h,&r);
	return r;
}

CRect CSystem::GetWindowResolution(){
	int screenwidth_real=GetSystemMetrics(SM_CXSCREEN);
	int screenheight_real=GetSystemMetrics(SM_CYSCREEN);
	CRect rectResult;
	rectResult.SetRect(0,0,screenwidth_real,screenheight_real);
	return rectResult;
}

int CSystem::GetVisibleHeight(){
	return GetSystemMetrics(SM_CYFULLSCREEN);
}

int main(){
	CSystem system;
	double x = system.GetCPUSpeedGHz();
	CRect rect = system.GetWindowResolution();
	int xx = rect.Width();
	int y = rect.Height();
	int sss = system.GetVisibleHeight();
	int screenwidth=GetSystemMetrics(SM_CXFULLSCREEN);
	int screenheight=GetSystemMetrics(SM_CYFULLSCREEN);
	//��������������ȡ����������Ļ�Ĵ�С����ʵ�ʵĴ�С
	int screenwidth_real=GetSystemMetrics(SM_CXSCREEN);
	int screenheight_real=GetSystemMetrics(SM_CYSCREEN);
	return 0;
}