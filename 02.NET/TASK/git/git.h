#ifndef __GIT__H
#define __GIT__H


//  �豸ʹ�����趨��
#define OLED 1			// �Ƿ�ʹ��OLED
#define NET_SERVE 1		// ƽ̨ѡ��
#define NETWORK_CHAEK 0 // �Ƿ������߼��
#define KEY_OPEN 1		// �Ƿ��������Ͷ̰����
#define USART2_OPEN 0	// �Ƿ�ʹ�ô��ڶ�

// ���ݶ���
typedef unsigned char U8;
typedef signed char S8;
typedef unsigned short U16;
typedef signed short S16;
typedef unsigned int U32;
typedef signed int S32;
typedef float F32;

//  C��
#include "cjson.h"
#include <string.h>
#include <stdio.h>
// ��Ƭ��ͷ�ļ�
#include "sys.h"
#include "usart.h"	 
// ����Э���
#include "Net.h"
// �����豸
#include "esp8266.h"

// ������
#include "task.h"
#include "timer.h"
// Ӳ������
#include "delay.h"
#include "usart.h"
#include "git.h"
#include "led.h"
#include "key.h"
#include "timer.h"
#include "flash.h"
#include "delay.h"
#include "HX711.h"
#include "level.h"
#include "relay.h"
#include "dht11.h"
#include "adc.h"

#if OLED // OLED�ļ�����
#include "oled.h"
#endif


// ��������Ϣ
#define SSID "NET"		// ·����SSID����
#define PASS "12345678" // ·��������
#if NET_SERVE == 0
// ��Э���������Onenet�ɰ�֧�֣�
#define ServerIP "183.230.40.39" // ������IP��ַ
#define ServerPort 6002			 // ������IP��ַ�˿ں�
#elif NET_SERVE == 1
// ����������ƽ̨��������֧�֣�
#define ServerIP "iot-06z00axdhgfk24n.mqtt.iothub.aliyuncs.com" // ������IP��ַ
#define ServerPort 1883											// ������IP��ַ�˿ں�
#elif NET_SERVE == 2
// EMQXƽ̨��������
#define ServerIP "broker.emqx.io" // ������IP��ַ
#define ServerPort 1883			  // ������IP��ַ�˿ں�
#endif

// �豸��Ϣ
#define PROID "smartdevice&h9sjuhzsSEm"															 // ��ƷID
#define DEVID "h9sjuhzsSEm.smartdevice|securemode=2,signmethod=hmacsha256,timestamp=1711934693928|" // �豸ID
#define AUTH_INFO "ecf72570a4f9fdcfaa13521bd2ae1672967410c6020abd8eeb73daa371d33c99"						 // ��Ȩ��Ϣ
// MQTT���� /broadcast/
#define S_TOPIC_NAME "/broadcast/h9sjuhzsSEm/test1" // ��Ҫ���ĵ�����
#define P_TOPIC_NAME "/broadcast/h9sjuhzsSEm/test2" // ��Ҫ����������

#define P_TOPIC_CMD "/sys/h9sjuhzsSEm/smartdevice/thing/event/property/post"

// �Զ��岼������
typedef enum
{
	MY_TRUE,
	MY_FALSE
} myBool;

// �Զ���ִ�н������
typedef enum
{
	MY_SUCCESSFUL = 0x01, // �ɹ�
	MY_FAIL = 0x00		  // ʧ��

} mySta; // �ɹ���־λ

typedef enum
{
	OPEN = 0x01, // ��
	CLOSE = 0x00 // �ر�

} On_or_Off_TypeDef; // �ɹ���־λ

typedef enum
{
	DERVICE_SEND = 0x00, // �豸->ƽ̨
	PLATFORM_SEND = 0x01 // ƽ̨->�豸

} Send_directino; // ���ͷ���

typedef struct
{
	U8 App;	 // ָ��ģʽ
	U8 Page; // ҳ��
	U8 Error_Time; //�������
	U8 Flage;	// ģʽѡ��
	U16 people; // ����
	U16 light;	// ����
	U16 somg;	// ����Ũ��

	F32 wight;		   // �仯����
	F32 git_wight;	   // �ۼ�����
	U8 wight_time;	   // ����ʱ��
	F32 average_wight; // ƽ������
	F32 add_wight;	   // �ۼ�����
	F32 Temp;		   // �¶�
	F32 Humi;		   // ʪ��
	U16 mq4;

} Data_TypeDef; // ���ݲ����ṹ��

typedef struct
{

	U16 somg_value; // ������ֵ
	U16 humi_value; // ʪ����ֵ
	U16 temp_value; // �¶���ֵ
	F32 wight_value; // ������ֵ
	
} Threshold_Value_TypeDef; // ���ݲ����ṹ��

typedef struct
{
	U8 door;
	U8 eat;
	U8 water;
	U8 open;
	U8 check_open; // ����Ƿ�������
	U16 time;  //ѭ����ʱʱ��
	U8 time_state; //ѭ����ʱ״̬
	U8 time_count; // ������
	U16 set_time1; // ��ʱ��
	
	U8 SG90_Turn;

} Device_Satte_Typedef; // ״̬�����ṹ��

// ȫ������
extern Data_TypeDef Data_init;
extern Device_Satte_Typedef device_state_init; // �豸״̬

extern Threshold_Value_TypeDef threshold_value_init; // �豸��ֵ���ýṹ��

// ��ȡ���ݲ���
mySta Read_Data(Data_TypeDef *Device_Data);
// ��ʼ��
mySta Reset_Threshole_Value(Threshold_Value_TypeDef *Value, Device_Satte_Typedef *device_state);
// ����OLED��ʾ��������
mySta Update_oled_massage(void);
// �����豸״̬
mySta Update_device_massage(void);
// ����json����
mySta massage_parse_json(char *message);
// ����
void Check_Key_ON_OFF(void);
// ��ʱ
void Automation_Close(void);

#endif
