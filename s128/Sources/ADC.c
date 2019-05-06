#include <MC9S12XS128.h>
#include "ADC.h"

unsigned char AD_value[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

unsigned char c=0;
/*************************************************************/
/*                       ADC��ʼ��                           */
/*************************************************************/
void ADC_Init(void) 
{
 
  ATD0CTL3 = 0x08;            // ��ͨ����ת�����ӳ��
  ATD0CTL4 = 0xb7;            // ѡ��8λ����ģ��ת��,ADģ��ʱ��Ƶ��Ϊ2MHz
  ATD0CTL5 = 0xa0;            // AD0��AD1��AD2����ͨ������,�Ҷ���ģʽ
  ATD0CTL2 = 0x40;            // ����A/Dת��,��������,��ֹ�ж�
}

/*************************************************************/
/*                        ��ADת��                         */
/*************************************************************/

void AD_Get_value(void)
{
  ATD0CTL5 =ATD0CTL5+c;               // ����ת��
             
 while(!ATD0STAT0_SCF);               // �ȴ�ADת��
                                 
  {if(c==0) 
    {
     AD_value[0]  = ATD0DR0L;
     AD_value[1]  = ATD0DR0H;
    }                                  // ACC_1
   else if(c==1) 
    {
     AD_value[2]  = ATD0DR0L;
     AD_value[3]  = ATD0DR0H;          // ACC_2
    }
       
  }
  c++;  
  if(c>1)
   c=0;
}

 