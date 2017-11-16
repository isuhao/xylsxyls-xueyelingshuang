#pragma once
#include <QtWidgets/QRadioButton>
#include "ControlBase.h"

class QWidget;
class RadioButton : public ControlBase < QRadioButton >
{
public:
	/** ���캯��
	@param [in] parent ������ָ��
	*/
	RadioButton(QWidget* parent = NULL);

	/** ����CheckBoxָʾ��ͼƬ
	@param [in] indicatorImg ����ͼƬ·�������·���б���ʹ����б��
	@param [in] indicatorImgStateCount ֻ����4��8����ʾ4̬��ť��8̬��ť
	@param [in] indicatorImgNormal ��ѡ�г�̬ͼƬ�������1��ʾ��ͼƬ����ָ�4�ݻ�8�ݣ�ѡ������ĵ�һ��
	@param [in] indicatorImgHover ��ѡ����ͣͼƬ
	@param [in] indicatorImgPressed ��ѡ�а���ͼƬ
	@param [in] indicatorImgDisabled ��ѡ�н���ͼƬ
	@param [in] indicatorImgCKNormal ѡ�г�̬ͼƬ
	@param [in] indicatorImgCKHover ѡ����ͣͼƬ
	@param [in] indicatorImgCKPressed ѡ�а���ͼƬ
	@param [in] indicatorImgCKDisabled ѡ�н���ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setIndicatorImage(const QString& indicatorImg,
			   			   int32_t indicatorImgStateCount = 4,
						   int32_t indicatorImgNormal = 1,
						   int32_t indicatorImgHover = 2,
						   int32_t indicatorImgPressed = 3,
						   int32_t indicatorImgDisabled = 4,
						   int32_t indicatorImgCKNormal = 1,
						   int32_t indicatorImgCKHover = 2,
						   int32_t indicatorImgCKPressed = 3,
						   int32_t indicatorImgCKDisabled = 4,
						   bool rePaint = false);

	/** ����CheckBoxָʾ������������ı���ͼƬ
	@param [in] backgroundImg ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ֻ����4��8����ʾ4̬��ť��8̬��ť
	@param [in] backgroundImgNormal ��ѡ�г�̬ͼƬ�������1��ʾ��ͼƬ����ָ�4�ݻ�8�ݣ�ѡ������ĵ�һ��
	@param [in] backgroundImgHover ��ѡ����ͣͼƬ
	@param [in] backgroundImgPressed ��ѡ�а���ͼƬ
	@param [in] backgroundImgDisabled ��ѡ�н���ͼƬ
	@param [in] backgroundImgCKNormal ѡ�г�̬ͼƬ
	@param [in] backgroundImgCKHover ѡ����ͣͼƬ
	@param [in] backgroundImgCKPressed ѡ�а���ͼƬ
	@param [in] backgroundImgCKDisabled ѡ�н���ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundImage(const QString& backgroundImg,
			   			    int32_t backgroundImgStateCount = 4,
						    int32_t backgroundImgNormal = 1,
						    int32_t backgroundImgHover = 2,
						    int32_t backgroundImgPressed = 3,
						    int32_t backgroundImgDisabled = 4,
						    int32_t backgroundImgCKNormal = 1,
						    int32_t backgroundImgCKHover = 2,
						    int32_t backgroundImgCKPressed = 3,
						    int32_t backgroundImgCKDisabled = 4,
							bool rePaint = false);

	/** ��������
	@param [in] fontName ������
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setFontFace(const QString& fontName, bool rePaint = false);

	/** ���������С
	@param [in] fontSize �����С
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setFontSize(int32_t fontSize, bool rePaint = false);

	/** ����������ɫ
	@param [in] ͬ�ϣ�8̬��ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setTextColor(const QColor& textNormalColor,
	 	 		 	  const QColor& textHoverColor,
					  const QColor& textPressedColor,
					  const QColor& textDisabledColor,
					  const QColor& textCkNormalColor,
					  const QColor& textCkHoverColor,
					  const QColor& textCkPressedColor,
					  const QColor& textCkDisabledColor,
					  bool rePaint = false);

	/** ���ñ�����ɫ��ָʾ������������ı�����ɫ
	@param [in] ͬ�ϣ�8̬��ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundColor(const QColor& backgroundNormalColor,
	 	 		 		    const QColor& backgroundHoverColor,
						    const QColor& backgroundPressedColor,
						    const QColor& backgroundDisabledColor,
						    const QColor& backgroundCkNormalColor,
						    const QColor& backgroundCkHoverColor,
						    const QColor& backgroundCkPressedColor,
						    const QColor& backgroundCkDisabledColor,
							bool rePaint = false);

	/** �����ı�ƫ����
	@param [in] origin �ı�ƫ����
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setTextOrigin(int32_t origin, bool rePaint = false);

	/** �ػ�
	*/
	void repaint();
};