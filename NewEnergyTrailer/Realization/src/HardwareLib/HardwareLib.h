/********************************************************************************
* 常州易控汽车电子股份有限公司
* (c) Copyright 2009-2017 ECTEK
* 保留所有权利
********************************************************************************
* 工程名称：整车控制器
* 文件名： HardwareLib.h
* 功能描述 ： 底层硬件驱总库
* 引用记录：该文件被GlobalDef.h包含
* 备注： 
* 修订记录：
*		日期		      版本		  作者		描述
*   2017.05.08  00.01.00     李中
*******************************************************************************/

#ifndef __HARDWARELIB_H
    #define __HARDWARELIB_H


    #include "Std_Types.h"
    

    /*******************************************************************************************
                                 公用函数库
    ********************************************************************************************/

    //一维查表插值
    uint16 Intpol_u16u16(uint16 * addrTablePUW, uint16 dataXUW); //1维查表插值，X,Y都是16位无符号整数
    uint16 Intpol_s16u16(uint16 * addrTablePUW, sint16 dataXW); //1维查表插值，X是有符号整数，Y是无符号整数
    sint16 Intpol_u16s16(uint16 * addrTablePUW, uint16 dataXUW);//1维查表插值，X是无符号整数，Y是有符号整数
    sint16 Intpol_s16s16(uint16 * addrTablePUW, sint16 dataXW); //1维查表插值，X,Y都是16位有符号整数

    //二维查表插值
    uint16 Intpol_u16u16u16(uint16 * addrTablePUW, uint16 dataXUW,uint16 dataYUW); //2维查表插值，X,Y,Z都是16位无符号整数
    sint16 Intpol_u16u16s16(uint16 * addrTablePUW, uint16 dataXUW,uint16 dataYUW);//2维查表插值，X,Y都是16位无符号，Z是有符号
    uint16 Intpol_u16s16u16(uint16 * addrTablePUW, uint16 dataXUW,sint16 dataYW); //2维查表插值，X,Z都是16位无符号，Y是有符号
    sint16 Intpol_s16u16s16(uint16 * addrTablePUW, sint16 dataXW,uint16 dataYUW); //2维查表插值，X,Z都是16位有符号，Y是无符号

    //PT1滤波
    #define _COMLIB_FACTOR_PT1  1000

    void ComLib_PT1U16Bit(uint16 valRawUW, uint16 K, uint16 T1, uint16 * valLstUW);
    void ComLib_PT1U32Bit(uint32 valRawUI, uint32 K, uint32 T1, uint32 * valLstUI);


    /*******************************************************************************************
                                 底层驱动接口
    ********************************************************************************************/      

    typedef enum
    {
        DSM_DIAG_OPENLOAD=0, /*开路*/
        DSM_DIAG_SHORTCIRCUIT,  /*短路*/
        DSM_DIAG_SHORTTOGND, /*短路到地*/
        DSM_DIAG_SHORTTOPWR /*短路到电源*/
    } DSM_idxDiagTypeE_TYPE;

    typedef enum
    {
        DSM_STATUS_OK=0x0, /*无故障*/
        DSM_STATUS_ERR=0x1, /*有故障*/
        DSM_STATUS_NVA=0xFF, /*故障状态未知或无效*/
    } DSM_stDiagE_TYPE;

    #define _PWM_DUTYCYCLE_FULL 10000U  //10000表示占空比为100.00%
    #define _PWM_DUTYCYCLE_FACTOR   100U

    #define _PWM_FREQ_FACTOR 10U //频率精度0。1Hz


    //模拟量输入
    #define _ATD_NUM_CHAN 24
    
    #define _ATD_INDEX_UBATTERY_CHAN 0   //蓄电池电压，内部连接
    #define _ATD_INDEX_ACCPED1_CHAN  1   //加速踏板1，对应接插件X46
    #define _ATD_INDEX_ACCPED2_CHAN  2   //加速踏板2，对应接插件X47
    #define _ATD_INDEX_BRAKE1_CHAN   3   //制动1，对应接插件X48
    #define _ATD_INDEX_BRAKE2_CHAN   4   //制动2，对应接插件X49
    #define _ATD_INDEX_RES4_CHAN     5   //电阻量4，对应接插件X87
    #define _ATD_INDEX_RES3_CHAN     6   //电阻量3，对应接插件X86
    #define _ATD_INDEX_RES2_CHAN     7   //电阻量2，对应接插件X85
    #define _ATD_INDEX_RES1_CHAN     8   //电阻量1，对应接插件X84
    #define _ATD_INDEX_CC_CHAN       9   //充电头CC信号，对应接插件X83
    #define _ATD_INDEX_CC2_CHAN      10  //充电头CC2信号，对应接插件X91
    #define _ATD_INDEX_BAK1_CHAN     12   //开关1信号，对应接插件X32
    #define _ATD_INDEX_BAK2_CHAN     13   //开关2信号，对应接插件X14
    #define _ATD_INDEX_BAK3_CHAN     14   //开关3信号，对应接插件X33
    #define _ATD_INDEX_BAK4_CHAN     15   //开关4信号，对应接插件X15
    #define _ATD_INDEX_BAK5_CHAN     16   //开关5信号，对应接插件X34
    #define _ATD_INDEX_BAK6_CHAN     17   //开关6信号，对应接插件X16
    #define _ATD_INDEX_BAK7_CHAN     18   //开关7信号，对应接插件X35
    #define _ATD_INDEX_BAK8_CHAN     19   //开关8信号，对应接插件X55
    #define _ATD_INDEX_BAK9_CHAN     20   //开关9信号，对应接插件X36
    #define _ATD_INDEX_BAK10_CHAN    21   //开关10信号，对应接插件X56
    #define _ATD_INDEX_BAK11_CHAN    22   //开关11信号，对应接插件X37
    #define _ATD_INDEX_BAK12_CHAN    23   //开关12信号，对应接插件X57

    uint16 ATDDrv_GetChanResult(uint8 idxChanUB); //得到上述通道的电压值
    
    
    //数字量输入
    #define _DIN_NUM_CHAN 24
    #define _DIN_NUM_ADCHAN  12 //前12路通过AD通道实现软件可配置上下拉

    #define _DIN_OPENLVL_LOW_STATE  0
    #define _DIN_OPENLVL_HIGH_STATE 1

    #define _DIN_INDEX_BAK1_CHAN    0   //开关1信号，对应接插件X32
    #define _DIN_INDEX_BAK2_CHAN    1   //开关2信号，对应接插件X14
    #define _DIN_INDEX_BAK3_CHAN    2   //开关3信号，对应接插件X33
    #define _DIN_INDEX_BAK4_CHAN    3   //开关4信号，对应接插件X15
    #define _DIN_INDEX_BAK5_CHAN    4   //开关5信号，对应接插件X34
    #define _DIN_INDEX_BAK6_CHAN    5   //开关6信号，对应接插件X16
    #define _DIN_INDEX_BAK7_CHAN    6   //开关7信号，对应接插件X35
    #define _DIN_INDEX_BAK8_CHAN    7   //开关8信号，对应接插件X55
    #define _DIN_INDEX_BAK9_CHAN    8   //开关9信号，对应接插件X36
    #define _DIN_INDEX_BAK10_CHAN   9   //开关10信号，对应接插件X56
    #define _DIN_INDEX_BAK11_CHAN   10  //开关11信号，对应接插件X37
    #define _DIN_INDEX_BAK12_CHAN   11  //开关12信号，对应接插件X57
    #define _DIN_INDEX_BAK13_CHAN   12  //开关13信号，对应接插件X38
    #define _DIN_INDEX_BAK14_CHAN   13  //开关14信号，对应接插件X51
    #define _DIN_INDEX_BAK15_CHAN   14  //开关15信号，对应接插件X70
    #define _DIN_INDEX_BAK16_CHAN   15  //开关16信号，对应接插件X52
    #define _DIN_INDEX_BAK17_CHAN   16  //开关17信号，对应接插件X71
    #define _DIN_INDEX_BAK18_CHAN   17  //开关18信号，对应接插件X53
    #define _DIN_INDEX_BAK19_CHAN   18  //开关19信号，对应接插件X110
    #define _DIN_INDEX_BAK20_CHAN   19  //开关20信号，对应接插件X111
    #define _DIN_INDEX_BAK21_CHAN   20  //开关21信号，对应接插件X101
    #define _DIN_INDEX_BAK22_CHAN   21  //开关22信号，对应接插件X102
    #define _DIN_INDEX_BAK23_CHAN   22  //开关23信号，对应接插件X103
    #define _DIN_INDEX_BAK24_CHAN   23  //开关24信号，对应接插件X104
    
    void DINDrv_SetChanThres(uint8 idxChanUB, uint8 stOpenLvlUB, uint16 uThresUW);
    uint8 DINDrv_GetChanState(uint8 idxChanUB); //得到上述通道开关状态
    
    
    //数字量输出
    #define _DO_NUM_CHAN  1

    #define _DO_INDEX_CPCTL_CHAN    0 //CP采样回路下拉电阻控制

    void DODrv_SetChanState(uint8 idxChanUB, uint8 bLvlUB); //bLvlUB表示电平状态，0为低电平，1为高电平


    //频率量采集
    #define _PULSEACQ_NUM_CHAN 4
    
    #define _PULSEACQ_INDEX_CP_CHAN     0 //充电头CP信号采集，对应接插件X96
    #define _PULSEACQ_INDEX_BAK1_CHAN   1 //频率信号1采集，对应接插件X20（负极对应X39）
    #define _PULSEACQ_INDEX_BAK2_CHAN   2 //频率信号2采集，对应接插件X73
    #define _PULSEACQ_INDEX_BAK3_CHAN   3 //频率信号3采集，对应接插件X97
    
    void PulseAcqDrv_GetChanFreq(uint8 idxChanUB, uint32 *fFreqUIP, uint16 *rDutyUWP); //获取通道的频率信息，频率精度0.1Hz/bit，占空比精度0.01%/bit
    void PulseAcqDrv_GetChanDura(uint8 idxChanUB, uint32 *tiPeriodUIP, uint32 *tiPosUIP); //获取通道的时间信息，时间精度0.02us/bit
    

    //PWM型信号输出及频率型低边驱动
    #define _PPWM_NUM_CHAN 18

	#define _PPWM_INDEX_FHBAK1_CHAN    0   //高边驱动1，对应接插件X62
    #define _PPWM_INDEX_FHBAK2_CHAN    1   //高边驱动2，对应接插件X80
    #define _PPWM_INDEX_FHBAK3_CHAN    2   //高边驱动3，对应接插件X59
    #define _PPWM_INDEX_FHBAK4_CHAN    3   //高边驱动4，对应接插件X22
    #define _PPWM_INDEX_FHBAK5_CHAN    4   //高边驱动5，对应接插件X77
    #define _PPWM_INDEX_FHBAK6_CHAN    5   //高边驱动6，对应接插件X76
    #define _PPWM_INDEX_FHBAK7_CHAN    6   //高边驱动7，对应接插件X75
    #define _PPWM_INDEX_FHBAK8_CHAN    7   //高边驱动8，对应接插件X74
    #define _PPWM_INDEX_FHBAK9_CHAN    8   //高边驱动9，对应接插件X121
    #define _PPWM_INDEX_FHBAK10_CHAN   9   //高边驱动10，对应接插件X118
    #define _PPWM_INDEX_FHBAK11_CHAN   10  //高边驱动11，对应接插件X116
    #define _PPWM_INDEX_FHBAK12_CHAN   11  //高边驱动12，对应接插件X117
    #define _PPWM_INDEX_FBAK1_CHAN     12  //频率信号输出1，对应接插件X41
    #define _PPWM_INDEX_FBAK2_CHAN     13  //频率信号输出2，对应接插件X42
    #define _PPWM_INDEX_FBAK3_CHAN     14  //频率信号输出3，对应接插件X23
    #define _PPWM_INDEX_FBAK4_CHAN     15  //频率信号输出4，对应接插件X58
    #define _PPWM_INDEX_FLBAK1_CHAN    16  //频率型低边驱动1，对应接插件X115
    #define _PPWM_INDEX_FLBAK2_CHAN    17  //频率型低边驱动2，对应接插件X114
    
    //该函数须放在10ms任务中调用
    void PPWMDrv_Interface(uint8 idxChanUB,uint32 fSetUI,uint16 rSetUW); //输出上述通道的低边驱动频率及占空比，频率精度0.1Hz/bit，占空比精度0.01%/bit
    DSM_stDiagE_TYPE PPWMDrv_GetChanDiagInfo(uint8 idxChanUB,DSM_idxDiagTypeE_TYPE idxDiagTypeE);

    //高低边驱动
    #define _PSWT_NUM_CHAN 20

    #define _PSWT_INDEX_HBAK1_CHAN    0    //高边驱动1，对应接插件X62
    #define _PSWT_INDEX_HBAK2_CHAN    1    //高边驱动2，对应接插件X80
    #define _PSWT_INDEX_HBAK3_CHAN    2    //高边驱动3，对应接插件X59
    #define _PSWT_INDEX_HBAK4_CHAN    3    //高边驱动4，对应接插件X22
    #define _PSWT_INDEX_HBAK5_CHAN    4    //高边驱动5，对应接插件X77
    #define _PSWT_INDEX_HBAK6_CHAN    5    //高边驱动6，对应接插件X76
    #define _PSWT_INDEX_HBAK7_CHAN    6    //高边驱动7，对应接插件X75
    #define _PSWT_INDEX_HBAK8_CHAN    7    //高边驱动8，对应接插件X74
    #define _PSWT_INDEX_HBAK9_CHAN    8    //高边驱动9，对应接插件X121
    #define _PSWT_INDEX_HBAK10_CHAN   9    //高边驱动10，对应接插件X118
    #define _PSWT_INDEX_HBAK11_CHAN   10   //高边驱动11，对应接插件X116
    #define _PSWT_INDEX_HBAK12_CHAN   11   //高边驱动12，对应接插件X117
	#define _PSWT_INDEX_LBAK1_CHAN    12   //低边驱动1，对应接插件X21
    #define _PSWT_INDEX_LBAK2_CHAN    13   //低边驱动2，对应接插件X24
    #define _PSWT_INDEX_LBAK3_CHAN    14   //低边驱动3，对应接插件X43
    #define _PSWT_INDEX_LBAK4_CHAN    15   //低边驱动4，对应接插件X17
    #define _PSWT_INDEX_LBAK5_CHAN    16   //低边驱动5，对应接插件X18
    #define _PSWT_INDEX_LBAK6_CHAN    17   //低边驱动6，对应接插件X19
    #define _PSWT_INDEX_LBAK7_CHAN    18   //低边驱动7，对应接插件X60
    #define _PSWT_INDEX_LBAK8_CHAN    19   //低边驱动8，对应接插件X61
    
    //该函数须放在10ms任务中调用
    void PSwtDrv_Interface(uint8 idxChanUB,uint8 bOpenUB); //输出上述通道的低边驱动状态, bOpen=1时为打开, 否则为关闭
    DSM_stDiagE_TYPE PSwtDrv_GetChanDiagInfo(uint8 idxChanUB,DSM_idxDiagTypeE_TYPE idxDiagTypeE);


    //CAN通讯接口
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
        MCAN_NODEMODE_MO = 0,  //MO模式下，每个MO对应一个具体的报文
        MCAN_NODEMODE_BUF = 1, //BUF模式，接收使用一个MO处理，其它MO成为发送缓存
        MCAN_NODEMODE_UNKNOWN = 0xFF,
    } MCANDrv_idxNodeModeE_TYPE;

    typedef union
    {
        uint32 U;
        struct
        {
            uint32 DLC       : 8; //数据长度
            uint32 DIR       : 1; //0为接收，1为发送
            uint32 IDE       : 1; //0为标准帧，1为扩展帧
            uint32 Reserved  : 6;
            uint32 CAN       : 8; //CAN通道号
            uint32 MO        : 8; //MO序号
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
        uint8  datMsgUBA[8]; //兼容CANFD
    } MCANDrv_infoMsgS_TYPE;

    typedef void (*pFunc_TxMsgCallback)(void);
    typedef void (*pFunc_RxMsgCallback)(MCANDrv_infoMsgS_TYPE infoMsgS);

    /*CAN设置函数*/
    uint8 MCANDrv_SetBaudrate(uint8 idxCANUB, uint32 baudrateUI);
    uint8 MCANDrv_SetCANMode(uint8 idxCANUB, MCANDrv_idxNodeModeE_TYPE idxNodeModeE);
    uint8 MCANDrv_SetMsgObj(const MCANDrv_infoMsgConfS_TYPE infoMsgConfS, void *pFunc);
    uint8 MCANDrv_SetCallbackFunc(uint8 idxCANUB, const pFunc_RxMsgCallback pRxFunc, const pFunc_TxMsgCallback pTxFunc);
    
    /*CAN操作函数*/
    MCAN_stRetE_TYPE MCANDrv_SendMsg(const MCANDrv_infoMsgS_TYPE infMsgS);

    uint8 MCANDrv_CheckIfBusOff(uint8 idxCANUB); //返回1表示有busoff错误


    /*EEPROM处理接口*/
    extern uint8 EEPROMDrv_bSaveInstantUB;  //用于立即触发EEPROM的存储，置1后可查询其值为0时表示存储完成


    //RTC时钟芯片操作接口
    typedef struct
    {
        uint8 datSecUB;
        uint8 datMinUB;
        uint8 datHourUB;
        uint8 datDateUB;
        uint8 datMonthUB;
        uint8 datYearUB;
    } RTCDrv_infoDateTimeS_TYPE;

    //设置或读取成功后返回TRUE，否则返回FALSE
    uint8 RTCDrv_SetDateTime(RTCDrv_infoDateTimeS_TYPE infoDateTimeS);
    uint8 RTCDrv_GetDateTime(RTCDrv_infoDateTimeS_TYPE *infoDateTimeSP);

    /*******************************************************************************************
                                 底层已处理物理量
    ********************************************************************************************/
    extern uint16 BattCD_uFltUW;  //蓄电池电压

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
    
    extern uint8 HardwareDrv_bBootloaderReqUB; //进入Bootloader请求，当出现该请求时会将BattCD_stWakeupU清零，在进入Afterrun时，进行进入安全状态的操作

    
    /*******************************************************************************************
                                整车控制状态
    *******************************************************************************************/
    #define _VEHCO_INDEX_STATUS_INIT 0
    #define _VEHCO_INDEX_STATUS_RUNNING 1
    #define _VEHCO_INDEX_STATUS_AFTERRUN 2
    #define _VEHCO_INDEX_STATUS_FINISH 3
    
    extern uint8 VehCo_stNewUB; //整车控制状态
    
    extern uint32 SysCon_tiRunLowUI; //从上次复位到现在系统的运行时间，单位s


    /*******************************************************************************************
     * 故障管理模块接口
     ******************************************************************************************/

     /*******************************************************************************************
                                   故障诊断
    ********************************************************************************************/
    #define _DSM_NUM_CONF_DFC_CHECKS 100  /*最大允许的故障号数*/
    #define _DSM_NUM_CONF_DINH_FIDS 32   /*最大允许的故障禁止操作数*/
    #define _DSM_NUM_CONF_DFES_ENTRIES 20  /*最大存储并向外报送的故障数*/
    #define _DINH_NUM_DFC_FID_MAX 6   /*每个故障号最多可关联的故障禁止操作数*/


    /*故障号定义DFC*/
    /*示例*/
    /*#define _DFC_INDEX_ACCPED_SIGHIGH 0*/ /*油门1信号ACCPED高*/
    /*#define _DFC_INDEX_ACCPED_SIGLOW 1*/ /*油门1信号ACCPED低*/
    /*#define _DFC_INDEX_ACCPED_SIGHNPL 2*/ /*油门信号ACCPED不合理*/
    /*#define _DFC_INDEX_ACCPED2_SIGHIGH 3*/ /*油门2信号ACCPED高*/
    /*#define _DFC_INDEX_ACCPED2_SIGLOW 4*/ /*油门2信号ACCPED低*/


    /*故障禁止操作定义FID*/
    /*底层用FID*/
    #define _DINH_INDEX_FID_DSM_WUC 0  /*故障诊断系统的暖机循环计数是否禁止*/
    #define _DINH_INDEX_FID_DSM_TST 1  /*下线检测故障屏蔽功能是否使用*/


    extern uint8 DFES_numMilUB; /*点亮故障灯的Memory Entry数目*/
    extern uint8 DFES_numSvsUB; /*点亮维修灯的Memory Entry数目*/
    extern uint8 DFES_bMilOnUB; /*故障灯是否点亮*/
    extern uint8 DFES_bMilBlinkUB; /*故障灯是否闪烁*/


    /*向DFC报告故障状*/
    /*使用举例:*/
    /*DFC_ReportFaultLevel(_DFC_INDEX_FTS_SIGHIGH,_DDRC_MASK_ANA_FT_LV_OK);*/
    /*DFC_ReportFaultLevel(_DFC_INDEX_FTS_SIGLOW,_DDRC_MASK_ANA_FT_LV_ERROR);*/
    #define _DDRC_MASK_ANA_FT_LV_OK       0x0
    #define _DDRC_MASK_ANA_FT_LV_ERROR    0xF

    void DFC_ReportFaultLevel(uint16 idxDFCUW,uint8 stFaultLevelUB);


    /*获取DFC的故障状态*/
    /*返回值为0时，表示该DFC无故障；返回值为1时，表示该DFC故障*/
    uint8 DFC_GetErrState(uint16 idxDFCUW);


    /*获取DFC的故障累积状态*/
    #define _DFC_INDEX_PRELIMINARILY_DEFECTIVE_STATUS 1
    #define _DFC_INDEX_FINALLY_DEFECTIVE_STATUS 2
    #define _DFC_INDEX_PRELIMINARILY_HEALED_STATUS 3
    #define _DFC_INDEX_FINALLY_HEALED_STATUS 4

    uint8 DFC_GetDebState(uint16 idxDFCUW);


    /*获取FID的状态*/
    /*返回值为0时，表示未触发该FID；为1时，表示触发了该FID*/
    uint8 DINH_GetFIDState(uint8 idxFIDUB);


#endif
