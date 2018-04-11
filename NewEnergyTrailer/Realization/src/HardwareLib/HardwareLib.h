/********************************************************************************
* �����׿��������ӹɷ����޹�˾
* (c) Copyright 2009-2017 ECTEK
* ��������Ȩ��
********************************************************************************
* �������ƣ�����������
* �ļ����� HardwareLib.h
* �������� �� �ײ�Ӳ�����ܿ�
* ���ü�¼�����ļ���GlobalDef.h����
* ��ע�� 
* �޶���¼��
*		����		      �汾		  ����		����
*   2017.05.08  00.01.00     ����
*******************************************************************************/

#ifndef __HARDWARELIB_H
    #define __HARDWARELIB_H


    #include "Std_Types.h"
    

    /*******************************************************************************************
                                 ���ú�����
    ********************************************************************************************/

    //һά����ֵ
    uint16 Intpol_u16u16(uint16 * addrTablePUW, uint16 dataXUW); //1ά����ֵ��X,Y����16λ�޷�������
    uint16 Intpol_s16u16(uint16 * addrTablePUW, sint16 dataXW); //1ά����ֵ��X���з���������Y���޷�������
    sint16 Intpol_u16s16(uint16 * addrTablePUW, uint16 dataXUW);//1ά����ֵ��X���޷���������Y���з�������
    sint16 Intpol_s16s16(uint16 * addrTablePUW, sint16 dataXW); //1ά����ֵ��X,Y����16λ�з�������

    //��ά����ֵ
    uint16 Intpol_u16u16u16(uint16 * addrTablePUW, uint16 dataXUW,uint16 dataYUW); //2ά����ֵ��X,Y,Z����16λ�޷�������
    sint16 Intpol_u16u16s16(uint16 * addrTablePUW, uint16 dataXUW,uint16 dataYUW);//2ά����ֵ��X,Y����16λ�޷��ţ�Z���з���
    uint16 Intpol_u16s16u16(uint16 * addrTablePUW, uint16 dataXUW,sint16 dataYW); //2ά����ֵ��X,Z����16λ�޷��ţ�Y���з���
    sint16 Intpol_s16u16s16(uint16 * addrTablePUW, sint16 dataXW,uint16 dataYUW); //2ά����ֵ��X,Z����16λ�з��ţ�Y���޷���

    //PT1�˲�
    #define _COMLIB_FACTOR_PT1  1000

    void ComLib_PT1U16Bit(uint16 valRawUW, uint16 K, uint16 T1, uint16 * valLstUW);
    void ComLib_PT1U32Bit(uint32 valRawUI, uint32 K, uint32 T1, uint32 * valLstUI);


    /*******************************************************************************************
                                 �ײ������ӿ�
    ********************************************************************************************/      

    typedef enum
    {
        DSM_DIAG_OPENLOAD=0, /*��·*/
        DSM_DIAG_SHORTCIRCUIT,  /*��·*/
        DSM_DIAG_SHORTTOGND, /*��·����*/
        DSM_DIAG_SHORTTOPWR /*��·����Դ*/
    } DSM_idxDiagTypeE_TYPE;

    typedef enum
    {
        DSM_STATUS_OK=0x0, /*�޹���*/
        DSM_STATUS_ERR=0x1, /*�й���*/
        DSM_STATUS_NVA=0xFF, /*����״̬δ֪����Ч*/
    } DSM_stDiagE_TYPE;

    #define _PWM_DUTYCYCLE_FULL 10000U  //10000��ʾռ�ձ�Ϊ100.00%
    #define _PWM_DUTYCYCLE_FACTOR   100U

    #define _PWM_FREQ_FACTOR 10U //Ƶ�ʾ���0��1Hz


    //ģ��������
    #define _ATD_NUM_CHAN 24
    
    #define _ATD_INDEX_UBATTERY_CHAN 0   //���ص�ѹ���ڲ�����
    #define _ATD_INDEX_ACCPED1_CHAN  1   //����̤��1����Ӧ�Ӳ��X46
    #define _ATD_INDEX_ACCPED2_CHAN  2   //����̤��2����Ӧ�Ӳ��X47
    #define _ATD_INDEX_BRAKE1_CHAN   3   //�ƶ�1����Ӧ�Ӳ��X48
    #define _ATD_INDEX_BRAKE2_CHAN   4   //�ƶ�2����Ӧ�Ӳ��X49
    #define _ATD_INDEX_RES4_CHAN     5   //������4����Ӧ�Ӳ��X87
    #define _ATD_INDEX_RES3_CHAN     6   //������3����Ӧ�Ӳ��X86
    #define _ATD_INDEX_RES2_CHAN     7   //������2����Ӧ�Ӳ��X85
    #define _ATD_INDEX_RES1_CHAN     8   //������1����Ӧ�Ӳ��X84
    #define _ATD_INDEX_CC_CHAN       9   //���ͷCC�źţ���Ӧ�Ӳ��X83
    #define _ATD_INDEX_CC2_CHAN      10  //���ͷCC2�źţ���Ӧ�Ӳ��X91
    #define _ATD_INDEX_BAK1_CHAN     12   //����1�źţ���Ӧ�Ӳ��X32
    #define _ATD_INDEX_BAK2_CHAN     13   //����2�źţ���Ӧ�Ӳ��X14
    #define _ATD_INDEX_BAK3_CHAN     14   //����3�źţ���Ӧ�Ӳ��X33
    #define _ATD_INDEX_BAK4_CHAN     15   //����4�źţ���Ӧ�Ӳ��X15
    #define _ATD_INDEX_BAK5_CHAN     16   //����5�źţ���Ӧ�Ӳ��X34
    #define _ATD_INDEX_BAK6_CHAN     17   //����6�źţ���Ӧ�Ӳ��X16
    #define _ATD_INDEX_BAK7_CHAN     18   //����7�źţ���Ӧ�Ӳ��X35
    #define _ATD_INDEX_BAK8_CHAN     19   //����8�źţ���Ӧ�Ӳ��X55
    #define _ATD_INDEX_BAK9_CHAN     20   //����9�źţ���Ӧ�Ӳ��X36
    #define _ATD_INDEX_BAK10_CHAN    21   //����10�źţ���Ӧ�Ӳ��X56
    #define _ATD_INDEX_BAK11_CHAN    22   //����11�źţ���Ӧ�Ӳ��X37
    #define _ATD_INDEX_BAK12_CHAN    23   //����12�źţ���Ӧ�Ӳ��X57

    uint16 ATDDrv_GetChanResult(uint8 idxChanUB); //�õ�����ͨ���ĵ�ѹֵ
    
    
    //����������
    #define _DIN_NUM_CHAN 24
    #define _DIN_NUM_ADCHAN  12 //ǰ12·ͨ��ADͨ��ʵ�����������������

    #define _DIN_OPENLVL_LOW_STATE  0
    #define _DIN_OPENLVL_HIGH_STATE 1

    #define _DIN_INDEX_BAK1_CHAN    0   //����1�źţ���Ӧ�Ӳ��X32
    #define _DIN_INDEX_BAK2_CHAN    1   //����2�źţ���Ӧ�Ӳ��X14
    #define _DIN_INDEX_BAK3_CHAN    2   //����3�źţ���Ӧ�Ӳ��X33
    #define _DIN_INDEX_BAK4_CHAN    3   //����4�źţ���Ӧ�Ӳ��X15
    #define _DIN_INDEX_BAK5_CHAN    4   //����5�źţ���Ӧ�Ӳ��X34
    #define _DIN_INDEX_BAK6_CHAN    5   //����6�źţ���Ӧ�Ӳ��X16
    #define _DIN_INDEX_BAK7_CHAN    6   //����7�źţ���Ӧ�Ӳ��X35
    #define _DIN_INDEX_BAK8_CHAN    7   //����8�źţ���Ӧ�Ӳ��X55
    #define _DIN_INDEX_BAK9_CHAN    8   //����9�źţ���Ӧ�Ӳ��X36
    #define _DIN_INDEX_BAK10_CHAN   9   //����10�źţ���Ӧ�Ӳ��X56
    #define _DIN_INDEX_BAK11_CHAN   10  //����11�źţ���Ӧ�Ӳ��X37
    #define _DIN_INDEX_BAK12_CHAN   11  //����12�źţ���Ӧ�Ӳ��X57
    #define _DIN_INDEX_BAK13_CHAN   12  //����13�źţ���Ӧ�Ӳ��X38
    #define _DIN_INDEX_BAK14_CHAN   13  //����14�źţ���Ӧ�Ӳ��X51
    #define _DIN_INDEX_BAK15_CHAN   14  //����15�źţ���Ӧ�Ӳ��X70
    #define _DIN_INDEX_BAK16_CHAN   15  //����16�źţ���Ӧ�Ӳ��X52
    #define _DIN_INDEX_BAK17_CHAN   16  //����17�źţ���Ӧ�Ӳ��X71
    #define _DIN_INDEX_BAK18_CHAN   17  //����18�źţ���Ӧ�Ӳ��X53
    #define _DIN_INDEX_BAK19_CHAN   18  //����19�źţ���Ӧ�Ӳ��X110
    #define _DIN_INDEX_BAK20_CHAN   19  //����20�źţ���Ӧ�Ӳ��X111
    #define _DIN_INDEX_BAK21_CHAN   20  //����21�źţ���Ӧ�Ӳ��X101
    #define _DIN_INDEX_BAK22_CHAN   21  //����22�źţ���Ӧ�Ӳ��X102
    #define _DIN_INDEX_BAK23_CHAN   22  //����23�źţ���Ӧ�Ӳ��X103
    #define _DIN_INDEX_BAK24_CHAN   23  //����24�źţ���Ӧ�Ӳ��X104
    
    void DINDrv_SetChanThres(uint8 idxChanUB, uint8 stOpenLvlUB, uint16 uThresUW);
    uint8 DINDrv_GetChanState(uint8 idxChanUB); //�õ�����ͨ������״̬
    
    
    //���������
    #define _DO_NUM_CHAN  1

    #define _DO_INDEX_CPCTL_CHAN    0 //CP������·�����������

    void DODrv_SetChanState(uint8 idxChanUB, uint8 bLvlUB); //bLvlUB��ʾ��ƽ״̬��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ


    //Ƶ�����ɼ�
    #define _PULSEACQ_NUM_CHAN 4
    
    #define _PULSEACQ_INDEX_CP_CHAN     0 //���ͷCP�źŲɼ�����Ӧ�Ӳ��X96
    #define _PULSEACQ_INDEX_BAK1_CHAN   1 //Ƶ���ź�1�ɼ�����Ӧ�Ӳ��X20��������ӦX39��
    #define _PULSEACQ_INDEX_BAK2_CHAN   2 //Ƶ���ź�2�ɼ�����Ӧ�Ӳ��X73
    #define _PULSEACQ_INDEX_BAK3_CHAN   3 //Ƶ���ź�3�ɼ�����Ӧ�Ӳ��X97
    
    void PulseAcqDrv_GetChanFreq(uint8 idxChanUB, uint32 *fFreqUIP, uint16 *rDutyUWP); //��ȡͨ����Ƶ����Ϣ��Ƶ�ʾ���0.1Hz/bit��ռ�ձȾ���0.01%/bit
    void PulseAcqDrv_GetChanDura(uint8 idxChanUB, uint32 *tiPeriodUIP, uint32 *tiPosUIP); //��ȡͨ����ʱ����Ϣ��ʱ�侫��0.02us/bit
    

    //PWM���ź������Ƶ���͵ͱ�����
    #define _PPWM_NUM_CHAN 18

	#define _PPWM_INDEX_FHBAK1_CHAN    0   //�߱�����1����Ӧ�Ӳ��X62
    #define _PPWM_INDEX_FHBAK2_CHAN    1   //�߱�����2����Ӧ�Ӳ��X80
    #define _PPWM_INDEX_FHBAK3_CHAN    2   //�߱�����3����Ӧ�Ӳ��X59
    #define _PPWM_INDEX_FHBAK4_CHAN    3   //�߱�����4����Ӧ�Ӳ��X22
    #define _PPWM_INDEX_FHBAK5_CHAN    4   //�߱�����5����Ӧ�Ӳ��X77
    #define _PPWM_INDEX_FHBAK6_CHAN    5   //�߱�����6����Ӧ�Ӳ��X76
    #define _PPWM_INDEX_FHBAK7_CHAN    6   //�߱�����7����Ӧ�Ӳ��X75
    #define _PPWM_INDEX_FHBAK8_CHAN    7   //�߱�����8����Ӧ�Ӳ��X74
    #define _PPWM_INDEX_FHBAK9_CHAN    8   //�߱�����9����Ӧ�Ӳ��X121
    #define _PPWM_INDEX_FHBAK10_CHAN   9   //�߱�����10����Ӧ�Ӳ��X118
    #define _PPWM_INDEX_FHBAK11_CHAN   10  //�߱�����11����Ӧ�Ӳ��X116
    #define _PPWM_INDEX_FHBAK12_CHAN   11  //�߱�����12����Ӧ�Ӳ��X117
    #define _PPWM_INDEX_FBAK1_CHAN     12  //Ƶ���ź����1����Ӧ�Ӳ��X41
    #define _PPWM_INDEX_FBAK2_CHAN     13  //Ƶ���ź����2����Ӧ�Ӳ��X42
    #define _PPWM_INDEX_FBAK3_CHAN     14  //Ƶ���ź����3����Ӧ�Ӳ��X23
    #define _PPWM_INDEX_FBAK4_CHAN     15  //Ƶ���ź����4����Ӧ�Ӳ��X58
    #define _PPWM_INDEX_FLBAK1_CHAN    16  //Ƶ���͵ͱ�����1����Ӧ�Ӳ��X115
    #define _PPWM_INDEX_FLBAK2_CHAN    17  //Ƶ���͵ͱ�����2����Ӧ�Ӳ��X114
    
    //�ú��������10ms�����е���
    void PPWMDrv_Interface(uint8 idxChanUB,uint32 fSetUI,uint16 rSetUW); //�������ͨ���ĵͱ�����Ƶ�ʼ�ռ�ձȣ�Ƶ�ʾ���0.1Hz/bit��ռ�ձȾ���0.01%/bit
    DSM_stDiagE_TYPE PPWMDrv_GetChanDiagInfo(uint8 idxChanUB,DSM_idxDiagTypeE_TYPE idxDiagTypeE);

    //�ߵͱ�����
    #define _PSWT_NUM_CHAN 20

    #define _PSWT_INDEX_HBAK1_CHAN    0    //�߱�����1����Ӧ�Ӳ��X62
    #define _PSWT_INDEX_HBAK2_CHAN    1    //�߱�����2����Ӧ�Ӳ��X80
    #define _PSWT_INDEX_HBAK3_CHAN    2    //�߱�����3����Ӧ�Ӳ��X59
    #define _PSWT_INDEX_HBAK4_CHAN    3    //�߱�����4����Ӧ�Ӳ��X22
    #define _PSWT_INDEX_HBAK5_CHAN    4    //�߱�����5����Ӧ�Ӳ��X77
    #define _PSWT_INDEX_HBAK6_CHAN    5    //�߱�����6����Ӧ�Ӳ��X76
    #define _PSWT_INDEX_HBAK7_CHAN    6    //�߱�����7����Ӧ�Ӳ��X75
    #define _PSWT_INDEX_HBAK8_CHAN    7    //�߱�����8����Ӧ�Ӳ��X74
    #define _PSWT_INDEX_HBAK9_CHAN    8    //�߱�����9����Ӧ�Ӳ��X121
    #define _PSWT_INDEX_HBAK10_CHAN   9    //�߱�����10����Ӧ�Ӳ��X118
    #define _PSWT_INDEX_HBAK11_CHAN   10   //�߱�����11����Ӧ�Ӳ��X116
    #define _PSWT_INDEX_HBAK12_CHAN   11   //�߱�����12����Ӧ�Ӳ��X117
	#define _PSWT_INDEX_LBAK1_CHAN    12   //�ͱ�����1����Ӧ�Ӳ��X21
    #define _PSWT_INDEX_LBAK2_CHAN    13   //�ͱ�����2����Ӧ�Ӳ��X24
    #define _PSWT_INDEX_LBAK3_CHAN    14   //�ͱ�����3����Ӧ�Ӳ��X43
    #define _PSWT_INDEX_LBAK4_CHAN    15   //�ͱ�����4����Ӧ�Ӳ��X17
    #define _PSWT_INDEX_LBAK5_CHAN    16   //�ͱ�����5����Ӧ�Ӳ��X18
    #define _PSWT_INDEX_LBAK6_CHAN    17   //�ͱ�����6����Ӧ�Ӳ��X19
    #define _PSWT_INDEX_LBAK7_CHAN    18   //�ͱ�����7����Ӧ�Ӳ��X60
    #define _PSWT_INDEX_LBAK8_CHAN    19   //�ͱ�����8����Ӧ�Ӳ��X61
    
    //�ú��������10ms�����е���
    void PSwtDrv_Interface(uint8 idxChanUB,uint8 bOpenUB); //�������ͨ���ĵͱ�����״̬, bOpen=1ʱΪ��, ����Ϊ�ر�
    DSM_stDiagE_TYPE PSwtDrv_GetChanDiagInfo(uint8 idxChanUB,DSM_idxDiagTypeE_TYPE idxDiagTypeE);


    //CANͨѶ�ӿ�
    #define _MCAN_NUM_CHAN     6
    #define _MCAN_NUM_MSGOBJ   32

    #define _MCAN_DIR_RX    0
    #define _MCAN_DIR_TX    1

    #define _MCAN_IDE_STD    0
    #define _MCAN_IDE_EXT    1

    typedef enum
    {
        MCAN_Status_ok                = 0x00000000,
        MCAN_Status_notInitialised    = 0x00000001,
        MCAN_Status_wrongParam        = 0x00000002,
        MCAN_Status_wrongPin          = 0x00000004,
        MCAN_Status_busHeavy          = 0x00000008,
        MCAN_Status_busOff            = 0x00000010,
        MCAN_Status_notSentBusy       = 0x00000020,
        MCAN_Status_receiveEmpty      = 0x00000040,
        MCAN_Status_messageLost       = 0x00000080,
        MCAN_Status_newData           = 0x00000100,
        MCAN_Status_newDataButOneLost = MCAN_Status_messageLost | MCAN_Status_newData
    } MCAN_stRetE_TYPE;

    typedef enum
    {
        MCAN_NODEMODE_MO = 0,  //MOģʽ�£�ÿ��MO��Ӧһ������ı���
        MCAN_NODEMODE_BUF = 1, //BUFģʽ������ʹ��һ��MO��������MO��Ϊ���ͻ���
        MCAN_NODEMODE_UNKNOWN = 0xFF,
    } MCANDrv_idxNodeModeE_TYPE;

    typedef union
    {
        uint32 U;
        struct
        {
            uint32 DLC       : 8; //���ݳ���
            uint32 DIR       : 1; //0Ϊ���գ�1Ϊ����
            uint32 IDE       : 1; //0Ϊ��׼֡��1Ϊ��չ֡
            uint32 Reserved  : 6;
            uint32 CAN       : 8; //CANͨ����
            uint32 MO        : 8; //MO���
        } B;
    } MCANDrv_infoMsgParU_TYPE;

    typedef struct 
    {
        MCANDrv_infoMsgParU_TYPE infoMsgParU;
        uint32 infoMsgIDUI;
    } MCANDrv_infoMsgConfS_TYPE;

    typedef struct
    {
        MCANDrv_infoMsgConfS_TYPE infoConfS;
        uint8  datMsgUBA[8]; //����CANFD
    } MCANDrv_infoMsgS_TYPE;

    typedef void (*pFunc_TxMsgCallback)(void);
    typedef void (*pFunc_RxMsgCallback)(MCANDrv_infoMsgS_TYPE infoMsgS);

    /*CAN���ú���*/
    uint8 MCANDrv_SetBaudrate(uint8 idxCANUB, uint32 baudrateUI);
    uint8 MCANDrv_SetCANMode(uint8 idxCANUB, MCANDrv_idxNodeModeE_TYPE idxNodeModeE);
    uint8 MCANDrv_SetMsgObj(const MCANDrv_infoMsgConfS_TYPE infoMsgConfS, void *pFunc);
    uint8 MCANDrv_SetCallbackFunc(uint8 idxCANUB, const pFunc_RxMsgCallback pRxFunc, const pFunc_TxMsgCallback pTxFunc);
    
    /*CAN��������*/
    MCAN_stRetE_TYPE MCANDrv_SendMsg(const MCANDrv_infoMsgS_TYPE infMsgS);

    uint8 MCANDrv_CheckIfBusOff(uint8 idxCANUB); //����1��ʾ��busoff����


    /*EEPROM����ӿ�*/
    extern uint8 EEPROMDrv_bSaveInstantUB;  //������������EEPROM�Ĵ洢����1��ɲ�ѯ��ֵΪ0ʱ��ʾ�洢���


    //RTCʱ��оƬ�����ӿ�
    typedef struct
    {
        uint8 datSecUB;
        uint8 datMinUB;
        uint8 datHourUB;
        uint8 datDateUB;
        uint8 datMonthUB;
        uint8 datYearUB;
    } RTCDrv_infoDateTimeS_TYPE;

    //���û��ȡ�ɹ��󷵻�TRUE�����򷵻�FALSE
    uint8 RTCDrv_SetDateTime(RTCDrv_infoDateTimeS_TYPE infoDateTimeS);
    uint8 RTCDrv_GetDateTime(RTCDrv_infoDateTimeS_TYPE *infoDateTimeSP);

    /*******************************************************************************************
                                 �ײ��Ѵ���������
    ********************************************************************************************/
    extern uint16 BattCD_uFltUW;  //���ص�ѹ

    typedef union
    {
        uint8 U;
        struct
        {
            uint8 bCAN      : 1;
            uint8 bLogic    : 1;
            uint8 bWkpSig1  : 1;
            uint8 bWkpSig2  : 1;
            uint8           : 4;
        } B;
    } BattCD_stWakeupU_TYPE;

    extern BattCD_stWakeupU_TYPE BattCD_stWakeupU;
    
    extern uint8 HardwareDrv_bBootloaderReqUB; //����Bootloader���󣬵����ָ�����ʱ�ὫBattCD_stWakeupU���㣬�ڽ���Afterrunʱ�����н��밲ȫ״̬�Ĳ���

    
    /*******************************************************************************************
                                ��������״̬
    *******************************************************************************************/
    #define _VEHCO_INDEX_STATUS_INIT 0
    #define _VEHCO_INDEX_STATUS_RUNNING 1
    #define _VEHCO_INDEX_STATUS_AFTERRUN 2
    #define _VEHCO_INDEX_STATUS_FINISH 3
    
    extern uint8 VehCo_stNewUB; //��������״̬
    
    extern uint32 SysCon_tiRunLowUI; //���ϴθ�λ������ϵͳ������ʱ�䣬��λs


    /*******************************************************************************************
     * ���Ϲ���ģ��ӿ�
     ******************************************************************************************/

     /*******************************************************************************************
                                   �������
    ********************************************************************************************/
    #define _DSM_NUM_CONF_DFC_CHECKS 100  /*�������Ĺ��Ϻ���*/
    #define _DSM_NUM_CONF_DINH_FIDS 32   /*�������Ĺ��Ͻ�ֹ������*/
    #define _DSM_NUM_CONF_DFES_ENTRIES 20  /*���洢�����ⱨ�͵Ĺ�����*/
    #define _DINH_NUM_DFC_FID_MAX 6   /*ÿ�����Ϻ����ɹ����Ĺ��Ͻ�ֹ������*/


    /*���ϺŶ���DFC*/
    /*ʾ��*/
    /*#define _DFC_INDEX_ACCPED_SIGHIGH 0*/ /*����1�ź�ACCPED��*/
    /*#define _DFC_INDEX_ACCPED_SIGLOW 1*/ /*����1�ź�ACCPED��*/
    /*#define _DFC_INDEX_ACCPED_SIGHNPL 2*/ /*�����ź�ACCPED������*/
    /*#define _DFC_INDEX_ACCPED2_SIGHIGH 3*/ /*����2�ź�ACCPED��*/
    /*#define _DFC_INDEX_ACCPED2_SIGLOW 4*/ /*����2�ź�ACCPED��*/


    /*���Ͻ�ֹ��������FID*/
    /*�ײ���FID*/
    #define _DINH_INDEX_FID_DSM_WUC 0  /*�������ϵͳ��ů��ѭ�������Ƿ��ֹ*/
    #define _DINH_INDEX_FID_DSM_TST 1  /*���߼��������ι����Ƿ�ʹ��*/


    extern uint8 DFES_numMilUB; /*�������ϵƵ�Memory Entry��Ŀ*/
    extern uint8 DFES_numSvsUB; /*����ά�޵Ƶ�Memory Entry��Ŀ*/
    extern uint8 DFES_bMilOnUB; /*���ϵ��Ƿ����*/
    extern uint8 DFES_bMilBlinkUB; /*���ϵ��Ƿ���˸*/


    /*��DFC�������״*/
    /*ʹ�þ���:*/
    /*DFC_ReportFaultLevel(_DFC_INDEX_FTS_SIGHIGH,_DDRC_MASK_ANA_FT_LV_OK);*/
    /*DFC_ReportFaultLevel(_DFC_INDEX_FTS_SIGLOW,_DDRC_MASK_ANA_FT_LV_ERROR);*/
    #define _DDRC_MASK_ANA_FT_LV_OK       0x0
    #define _DDRC_MASK_ANA_FT_LV_ERROR    0xF

    void DFC_ReportFaultLevel(uint16 idxDFCUW,uint8 stFaultLevelUB);


    /*��ȡDFC�Ĺ���״̬*/
    /*����ֵΪ0ʱ����ʾ��DFC�޹��ϣ�����ֵΪ1ʱ����ʾ��DFC����*/
    uint8 DFC_GetErrState(uint16 idxDFCUW);


    /*��ȡDFC�Ĺ����ۻ�״̬*/
    #define _DFC_INDEX_PRELIMINARILY_DEFECTIVE_STATUS 1
    #define _DFC_INDEX_FINALLY_DEFECTIVE_STATUS 2
    #define _DFC_INDEX_PRELIMINARILY_HEALED_STATUS 3
    #define _DFC_INDEX_FINALLY_HEALED_STATUS 4

    uint8 DFC_GetDebState(uint16 idxDFCUW);


    /*��ȡFID��״̬*/
    /*����ֵΪ0ʱ����ʾδ������FID��Ϊ1ʱ����ʾ�����˸�FID*/
    uint8 DINH_GetFIDState(uint8 idxFIDUB);


#endif
