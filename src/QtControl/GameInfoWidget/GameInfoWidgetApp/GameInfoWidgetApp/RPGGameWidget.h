#pragma once
#include <QWidget>
#include <QUrl>
#include <stdint.h>
#include "ExternalControls/ComboBox.h"

class QEvent;
class QObject;
class Label;
class CWebViewEx;
class LineEdit;
class CheckBox;
class COriginalButton;
class CPasswordInputBox;
class RPGGameWidget : public QWidget
{
	Q_OBJECT
public:
	/** ���캯��
	@param [in] parent ������ָ��
	*/
	RPGGameWidget(QWidget* parent = NULL);

	/** ��������
	*/
	virtual ~RPGGameWidget();

	/** ������Ϸ������
	@param [in] gameName ��Ϸ������
	*/
	void setGameName(const QString& gameName);

	/** ��ȡ��Ϸ������
	@return ������Ϸ������
	*/
	QString getGameName();

	/** ������Ϸ�������Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setGameNameEnable(bool enable);

	/** ������Ϸ������
	@param [in] gamePassword ��Ϸ������
	*/
	void setGamePassword(const QString& gamePassword);

	/** ��ȡ��Ϸ������
	@return ������Ϸ������
	*/
	QString getGamePassword();

	/** ������Ϸ�������Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setGamePasswordEnable(bool enable);

	/** ������Ϸ��ģʽ
	@param [in] gameModeList ��Ϸ��ģʽ
	*/
	void setGameModeList(const QStringList& gameModeList);

	/** ���õ�ǰ��Ϸ��ģʽ
	@param [in] gameMode ��Ϸ��ģʽ
	*/
	void setCurGameMode(const QString& gameMode);

	/** ��ȡ��ǰѡ�����Ϸ��ģʽ
	@return ���ص�ǰѡ�����Ϸ��ģʽ
	*/
	QString getCurGameMode();

	/** ������Ϸ��ģʽ�Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setGameModeEnable(bool enable);

	/** ������������
	@param [in] gameNetList ��������
	*/
	void setGameNetList(const QStringList& gameNetList);

	/** ���õ�ǰ��������
	@param [in] gameNet ��������
	*/
	void setCurGameNet(const QString& gameNet);

	/** ��ȡ��ǰѡ�����������
	@return ���ص�ǰѡ�����������
	*/
	QString getCurGameNet();

	/** �������������Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setGameNetEnable(bool enable);

	/** ���õ���������
	@param [in] gameLeaveList ����������
	*/
	void setGameLeaveList(const QStringList& gameLeaveList);

	/** ��ȡ��ǰ����������
	@param [in] gameLeave ����������
	*/
	void setCurGameLeave(const QString& gameLeave);

	/** ��ȡ��ǰѡ��ĵ���������
	@return ���ص�ǰѡ��ĵ���������
	*/
	QString getCurGameLeave();

	/** ���õ����������Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setGameLeaveEnable(bool enable);

	/** �����Ƿ�������λ
	@param [in] judge �Ƿ�������λ
	*/
	void setJudge(bool judge);

	/** ��ȡ��ǰ�Ƿ����˲���λ
	@return ���ص�ǰ�Ƿ����˲���λ
	*/
	bool getJudge();

	/** ���ò���λ�Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setJudgeEnable(bool enable);

	/** ���ñ����Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setSaveEnable(bool enable);

	/** ������������Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setInviteFriendEnable(bool enable);

	/** ��������Ƿ����
	@return ������������Ƿ����
	*/
	bool isInviteFriendEnable();

	/** ���ÿ�ʼ��Ϸ�Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setStartGameEnable(bool enable);

	/** ��ʼ��Ϸ�Ƿ����
	@return ���ؿ�ʼ��Ϸ�Ƿ����
	*/
	bool isStartGameEnable();

	/** ����׼����Ϸ�Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setPrepareGameEnable(bool enable);

	/** ����׼����Ϸ�Ƿ�Ϊ����״̬
	@param [in] check �Ƿ�Ϊ����״̬
	*/
	void setPrepareGameCheck(bool check);

	/** ׼����Ϸ�Ƿ����
	@return ����׼����Ϸ�Ƿ����
	*/
	bool isPrepareGameEnable();

	/** �����˳��Ƿ����
	@param [in] enable �Ƿ����
	*/
	void setExitEnable(bool enable);

	/** �˳��Ƿ����
	@return �����˳��Ƿ����
	*/
	bool isExitEnable();

	/** ������Ϸ���ý�����ҳ����
	@param [in] web ��ַ
	*/
	void setGameSettingWebView(const QString& web);

	/** ���ø���ս��������ҳ����
	@param [in] web ��ַ
	*/
	void setPersonalRecordWebView(const QString& web);

	/** �����ҵĵ��߽�����ҳ����
	@param [in] web ��ַ
	*/
	void setMyToolWebView(const QString& web);

	/** ����ҳ�������пؼ�
	*/
	void resetSettings();

	/** �����Ƿ�Ϊ������������ʾ��ʼ��Ϸ����������ʾ׼����Ϸ
	@param [in] isLeader �Ƿ�Ϊ����
	*/
	void setLeader(bool isLeader);

	/** �����Ϸ���ý���
	*/
	void clickGameSetting();

	/** �������ս������
	*/
	void clickPersonalRecord();

	/** ����ҵĵ��߽���
	*/
	void clickMyTool();

private:
	/** Ĭ�����ݳ�ʼ��
	*/
	void init();

	void initGameSettingButton();
	void initPersonalRecordButton();
	void initMyToolButton();

	void initGameSettingWidget();
	void initPersonalRecordWidget();
	void initMyToolButtonWidget();

	//����ַ����������ʾ�������������ʽ
	void setComboBoxAttri(ComboBox* pBox,
						  const std::wstring& pattern = L"",
						  QRegExp* ex = nullptr,
						  QRegExpValidator* rep = nullptr);

	void comboBoxTextChanged(const QString& text,
							 ComboBox* pBox,
							 const QRegExp& exp,
							 const std::wstring& addString,
							 std::wstring& curText);

	void comboBoxEditFinish(ComboBox* pBox, const std::wstring& addString, std::wstring& curText, bool& finish);

	void comboBoxPress(QObject* target,
					   ComboBox* pBox,
					   const std::wstring& addString,
					   std::wstring& curText,
					   bool& finish);

	void comboBoxFocusOut(QObject* target,
						  ComboBox* pBox,
						  const std::wstring& addString,
						  std::wstring& curText,
						  bool& finish);

	void resizeEvent(QResizeEvent* eve);
	//���пؼ�ͳһ����
	void layout();

	bool eventFilter(QObject* target, QEvent* eve);

private slots:
	void onGameSettingClicked();
	void onPersonalRecordClicked();
	void onMyToolClicked();
	void onGameSettingUrlLinkClicked(const QUrl& url);
	void onPersonalRecordUrlLinkClicked(const QUrl& url);
	void onMyToolUrlLinkClicked(const QUrl& url);
	void onPrepareGameClicked();
	void onNetEditTextFinish();
	void onLeaveEditTextFinish();
	void onGameNetTextChanged(const QString& text);
	void onGameLeaveTextChanged(const QString& text);

Q_SIGNALS:
	void onSaveClicked();
	void onInviteFriendClicked();
	void onStartGameClicked();
	void prepareGameClicked();
	void cancelPrepareGameClicked();
	void onExitClicked();
	void onGameNameChanged(const QString &);
	void onGamePasswordChanged(const QString &);
	void onGameModeChanged(const QString&);
	void onGameNetChanged(const QString &);
	void onGameLeaveChanged(const QString &);
	void onJudgeChanged(int);
	void onGameSettingLinkClicked(const QString&);
	void onPersonalRecordLinkClicked(const QString&);
	void onMyToolLinkClicked(const QString&);
	
private:
	COriginalButton* m_gameSetting;
	COriginalButton* m_personalRecord;
	COriginalButton* m_myTool;

	QWidget* m_gameSettingWidget;
	QWidget* m_personalRecordWidget;
	QWidget* m_myToolWidget;

	LineEdit* m_gameNameEdit;
	CPasswordInputBox* m_gamePasswordEdit;
	ComboBox* m_gameModeComboBox;
	ComboBox* m_gameNetComboBox;
	ComboBox* m_gameLeaveComboBox;
	CheckBox* m_judgeCheckBox;

	COriginalButton* m_inviteFriend;
	COriginalButton* m_startGame;
	COriginalButton* m_prepareGame;
	COriginalButton* m_exit;

	CWebViewEx* m_myToolWebView;
	CWebViewEx* m_personalRecordWebView;
	CWebViewEx* m_gameSettingWebView;

	Label* m_gameName;
	Label* m_gamePassword;
	Label* m_gameMode;
	Label* m_gameNet;
	Label* m_gameLeave;
	Label* m_checkBox;
	Label* m_lab;
	Label* m_rect;
	COriginalButton* m_save;

	//��������߶�
	int32_t m_gameInfoWidgetHeight;

	//��ť��Ӧ��widget�߶�
	int32_t m_widgetHeight;

	//��Ϸ������ҳ��ʼ�߶�
	int32_t m_gameSettingWebviewOrigin;

	//������Ѱ�ť��ʼ�߶�
	int32_t m_inviteFriendOrigin;

	// ��ʼ��Ϸ��ť������ʼλ��
	int32_t m_startGameOrigin_y;

	//�˳���ť������ʼλ��
	int32_t m_exitOrigin_y;

	QRegExpValidator m_netRep;
	QRegExpValidator m_leaveRep;

	QRegExp m_netExp;
	QRegExp m_leaveExp;

	std::wstring m_gameNetCurText;
	std::wstring m_gameLeaveCurText;

	QString m_war3ResourcePath;
	bool m_isLeader;

	bool m_netFinish;
	bool m_leaveFinish;
};