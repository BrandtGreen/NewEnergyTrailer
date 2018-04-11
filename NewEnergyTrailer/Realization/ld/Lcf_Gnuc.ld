
/*
 * Name: iROM.ld 
 * 
 * Generated Linker Description File
 * Copyright (C) 2010 HighTec EDV-Systeme GmbH. 
 * (!Do not edit outsite of the protection areas!)
 *
 * Description: 
 * internal flash configuration
 */
 
OUTPUT_FORMAT("elf32-tricore")
OUTPUT_ARCH(tricore)

/*
 * Define Entrypoint of Executable
 */
ENTRY(_start)

/*
 * Global
 */
/*Program Flash Memory (PFLASH0)*/ 
__PMU_PFLASH0_BEGIN = 0x80000000;
__PMU_PFLASH0_END = 0x80200000;
__PMU_PFLASH0_SIZE = 2M;
/*Data Flash Memory (DFLASH0)*/ 
__PMU_DFLASH0_BEGIN = 0xAF000000;
__PMU_DFLASH0_SIZE = 128K;
/*Boot ROM (BROM)*/ 
__BROM_BEGIN = 0x8FFF8000;
__BROM_SIZE = 32K;
/*Scratch-Pad RAM (PSPR)*/ 
__PMI_PSPR_BEGIN = 0xC0000000;
__PMI_PSPR_SIZE = 8K;
/*Local Data RAM (DSPR)*/ 
__DMI_DSPR_BEGIN = 0xD0000000;
__DMI_DSPR_SIZE = 184K;
/*Local Data RAM (DSPR)*/ 
__LMU_SRAM_BEGIN = 0x90000000;
__LMU_SRAM_SIZE = 32K;


__USTACK_SIZE = 8K;  /* Section for ustack*/ 
__ISTACK_SIZE = 2K;  /* Section for istack*/ 
__HEAP_SIZE = 4K;  /* Section for heap*/ 
__CSA_SIZE = 16K;  /* Section for CSA*/

__CALDATA_SIZE = 64K;
__CALDATAVER_SIZE = 512;
__CALDATA_START = 0xA0080000;
__CALDATA_END = 0xA0090000;

__INTVEC0_START = 0x80020000;

/**
 *	User defined global region
 */
/*PROTECTED REGION ID(Protection:iROM-Global) ENABLED START*/
/*Protection-Area for your own LDF-Code*/
/*PROTECTED REGION END*/

/*
 * internal flash configuration
 */
MEMORY
{
    /*PFLASH S0*/
	PMU_STARTUP (rx!p): 	org = 0x80000000, len = 16K /*Startup Section*/
	
	/*PFLASH S1*/
	PMU_CODE_VERIFY (r!xp): org = 0x80004000, len = 16K /*Code Verify Section*/
	
	/*PFLASH S2*/
	PMU_ECUSN (r!xp): org = 0x80008000, len = 16K /*ECUSN Section*/
	
	PMU_PFLASH0_S5 (rx!p):  org = 0x80014000, len = 16K /*a specific purpose with an enabled tuning protection*/
	PMU_PFLASH0_S5_nc (rx!p): org = 0xA0014000, len = 16K
	PMU_PFLASH0_S6 (rx!p):  org = 0x80018000, len = 16K /*HSM code section*/
    PMU_PFLASH0_S6_nc (rx!p): org = 0xA0018000, len = 16K
    
    /*PFLASH S7*/
    PMU_TRAP (rx!p): org = 0x8001C000, len = 16K /*Trap function*/
    
    /*PFLASH S8*/
    PMU_INTVEC (rx!p): org = 0x80020000, len = 22K /*Interrupt Vectors*/
    PMU_MAIN   (rx!p): org = 0x80025800, len = 2K /*Main Function*/
    PMU_CLEARTAB (rx!p): org = 0x80026000, len = 4K /*__clear_tab*/
    PMU_COPYTAB (rx!p): org = 0x80027000, len = 4K /*__copy_tab*/
    
    PMU_PFLASH0_S9_S12 (rx!p): org = 0x80028000, len = 128K
    PMU_PFLASH0_S9_S12_nc (rx!p): org = 0xA0028000, len = 128K
    
    /*PFLASH S13-S14*/
    PMU_BOOTLOADER (rx!p):  org = 0x80048000, len = 32K /*Bootloader Code Section*/
    PMU_BOOTLOADER_FR (rx!p): org = 0x80050000, len = 8K /*Bootloader Flash Routine*/
    PMU_BOOTLOADER_CONT (r!xp): org = 0x80052000, len = 8K /*Bootloader Const Section*/
    
    /*PFLASH S15*/
    PMU_SOFTINFO (r!xp): org = 0x80058000, len = 6K /*Software Information*/
    PMU_APPINFO (r!xp): org = 0x80059800, len = 2K /*Application Information*/   
    PMU_EOLINIT (r!xp): org = 0x8005A000, len = 8K /*EOL初始数据*/
    
    PMU_PFLASH0_S16_S17 (rx!p):  org = 0x80060000, len = 128K /*HSM code section*/
    PMU_PFLASH0_S16_S17_nc (rx!p): org = 0xA0060000, len = 128K
    
    /*PFLASH S18*/
	PMU_MAP (r!xp): 		org = 0x80080000, len = 64K /*MAP Section*/
	PMU_MAP_nc (r!xp):	    org = 0xA0080000, len = 64K
	
	PMU_PFLASH0_S19 (rx!p): org = 0x80090000, len = 64K
	PMU_PFLASH0_S19_nc (rx!p): org = 0xA0090000, len = 64K
	
	/*PFLASH S20-S26*/
	PMU_PFLASH0 (rx!p):	    org = 0x800A0000, len = 1408K  /*Program Flash Memory (PFLASH0)*/
	PMU_PFLASH0_nc (rx!p):  org = 0xA00A0000, len = 1408K
	 
	PMU_DFLASH0 (r!xp):	org = 0xAF000000, len = 128K  /*Data Flash Memory (DFLASH0)*/
	 
	BROM (rx!p):	org = 0x8FFF8000, len = 32K  /*Boot ROM (BROM)*/ 
	
	PMI_PSPR_LOCAL (wx!p):	org = 0xC0000000, len = 8K  /*Scratch-Pad RAM (PSPR)*/
	PMI_PSPR (wx!p):  org = 0x70100000, len = 8K 
	
	DMI_CALRAM_LOCAL (w!xp):  org = 0xD0000000, len = 64K /*Calibration RAM*/ 
	DMI_CALRAM (w!xp): org = 0x70000000, len = 64K
	
	DMI_EEP_EOLRAM (w!xp): org = 0xD0010008, len = 8K-8 /*EEPROM EOL RAM, 在Flash里有备份*/
	DMI_EEP_RUNPARRAM (w!xp): org = 0xD0012008, len = 1K-8 /*EEPROM Run Par RAM，在Flash里i没有备份*/
	DMI_EEP_DIAGRAM (w!xp): org = 0xD0012400, len = 2K /*EEPROM Diagnostic RAM，在Flash里没有备份*/
	DMI_EEP_RUNINFORAM (w!xp): org = 0xD0012C00, len = 5K /*EEPROM Run Info RAM，在Flash里没有备份*/
	
	DMI_BOOTLOADER_RAM (w!xp): org = 0xD0014000, len = 1K /*Bootloader RAM*/
	
	DMI_USTACK (w!xp): org = 0xD0014400, len = 8K /*USTACK*/
	DMI_ISTACK (w!xp): org = 0xD0016400, len = 2K /*ISTACK*/
	DMI_HEAP (w!xp): org = 0xD0016C00, len = 4K /*HEAP*/
	DMI_CSA (w!xp): org = 0xD0017C00, len = 16K /*CSA*/
	
	DMI_DSPR (w!xp):	org = 0xD001BC00, len = 73K  /*Local Data RAM (DSPR)*/	
}			

SECTIONS
{
	/*Code-Sections*/
	
	/*
	 * Startup code for TriCore
	 */
	.startup_code  :
	{
		PROVIDE(__startup_code_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .startup_code.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		KEEP(*(.startup_code)) /*Startup code for TriCore*/ 
		KEEP(*(.startup_code*))
		
		/*PROTECTED REGION ID(Protection: iROM .startup_code) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__startup_code_end = .);
		. = ALIGN(8);
		
	} > PMU_STARTUP
	
	
	
	/*
     *Bootloader code
     */
     
	.bootloader_code  :
	{
	   PROVIDE(__BOOTLOADER_CODE_START = .);
	   
	   KEEP(*(.bootloader_entry))
       
	   KEEP(*(.bootloader_code))
	   
	   PROVIDE(__BOOTLOADER_CODE_END = .);		
	} > PMU_BOOTLOADER
	
	.bootloader_fr :
	{
	   PROVIDE(__BOOTLOADER_FR_START = .);
	   
	   KEEP(*(.bootloader_fr))
       
       PROVIDE(__BOOTLOADER_FR_END = .);
       
	} > PMU_BOOTLOADER_FR
	
	.bootloader_const :
	{
	   PROVIDE(__BOOTLOADER_CONST_START = .);
	   
	   KEEP(*(.bootloader_const))
	   
	   PROVIDE(__BOOTLOADER_CONST_END = .);
	   
	} > PMU_BOOTLOADER_CONT
	
    .bootloader_ram :
    {
        PROVIDE(__BOOTLOADER_RAM_START = .);
        
        KEEP(*(.bootloader_ram))
        
        PROVIDE(__BOOTLOADER_RAM_END = .);
        
    } > DMI_BOOTLOADER_RAM
    
    
	/*
     *Code Verify
     */
	.code_verify :
	{
	   PROVIDE(__CODE_VERIFY_START = .);
	   
	   KEEP(*(.code_verify))
	   
	   PROVIDE(__CODE_VERIFY_END = .);
	   
	} > PMU_CODE_VERIFY
	
	
	/*
     *ECUSN
     */
	
	.ecusn_const :
	{
	   PROVIDE(__ECUSN_CONST_START = .);
	   
	   KEEP(*(.ecusn_const))
	   
	   PROVIDE(__ECUSN_CONST_END = .);
	   
	} > PMU_ECUSN
	
	
	/*
     *Calibration data
     */
	. = __CALDATA_START;
    .cal_data  : 
    {
        KEEP(*(.cal_data_ver))
        . = __CALDATAVER_SIZE;
        KEEP(*(.cal_data))
        . = __CALDATA_SIZE;
    } > PMU_MAP_nc
	
	.calram_data  :
	{
		KEEP(*(.calram_data)) 
		
	} > DMI_CALRAM
	
	
	/*用于存储软件版本等信息*/
    .soft_info :
    {
        KEEP(*(.soft_info))
    } > PMU_SOFTINFO
    
    .application_info :
    {
        KEEP(*(.applayer_info))
    } > PMU_APPINFO
    
    /*EOL数据区*/
    .eol_data :
    {
        PROVIDE(__EOL_DATA_START = .);
       
        KEEP(*(.eol_data))
       
        PROVIDE(__EOL_DATA_END = .);
        
    } > DMI_EEP_EOLRAM AT > PMU_PFLASH0
    
    .eol_initdata :
    {
        PROVIDE(__EOL_INITDATA_START = .);
       
        KEEP(*(.eol_initdata))
        
        PROVIDE(__EOL_INITDATA_END = .);
    } > PMU_EOLINIT
    
    /*诊断数据区*/
    .diag_data :
    {
        PROVIDE(__DIAG_DATA_START = .);
       
        KEEP(*(.diag_data))
       
        PROVIDE(__DIAG_DATA_END = .);
        
    } > DMI_EEP_DIAGRAM
    
    /*RunPar的EEPROM数据区*/
    .runpar_data :
    {
        PROVIDE(__RUNPAR_DATA_START = .);
   
        KEEP(*(.runpar_data))
   
        PROVIDE(__RUNPAR_DATA_END = .);
        
    } > DMI_EEP_RUNPARRAM
    
    /*Runinfo的EEPROM数据区*/
    .runinfo_data :
    {
        PROVIDE(__RUNINFO_DATA_START = .);
        
        KEEP(*(.runinfo_data))
        
        PROVIDE(__RUNINFO_DATA_END = .);
        
    } > DMI_EEP_RUNINFORAM  AT > PMU_PFLASH0
    
    
	/*
	 * Code section
	 */
	.main_function :
	{
	   KEEP(*(.main_function))
	} > PMU_MAIN 
	 
	.text  :
	{
		PROVIDE(__text_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .text.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

        PROVIDE(__FLASH_FUNCTION_START = .);
        KEEP(*(.flash_function))
        PROVIDE(__FLASH_FUNCTION_END = .);

		*(.text) /*Code section*/ 
		*(.text*)
		*(.gnu.linkonce.t.*)
		
		/*PROTECTED REGION ID(Protection: iROM .text) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__text_end = .);
		. = ALIGN(8);
		
	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */
	
	.pflash0_reserved :
    {
       *(.text) /*Code section*/ 
        *(.text*)
        *(.gnu.linkonce.t.*)
        
        . = ALIGN(8);
                
    } > PMU_PFLASH0_S19 
    
    .pflash0_other :
    {
       *(.text) /*Code section*/ 
        *(.text*)
        *(.gnu.linkonce.t.*)  
        
        . = ALIGN(8);
              
    } > PMU_PFLASH0_S9_S12
    
    
    /*
     * Code executed before calling main
     */
    .init  :
    {
        PROVIDE(__init_start = .);
        
        /*PROTECTED REGION ID(Protection: iROM .init.begin) ENABLED START*/
            /*Protection-Area for your own LDF-Code*/
        /*PROTECTED REGION END*/
        
        KEEP(*(.init)) /*Code executed before calling main*/ 
        KEEP(*(.init*))
        
        /*PROTECTED REGION ID(Protection: iROM .init) ENABLED START*/
            /*Protection-Area for your own LDF-Code*/
        /*PROTECTED REGION END*/
        
        PROVIDE(__init_end = .);
        . = ALIGN(8);
        
    } > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
    
    /*
     * Code executed before exiting program
     */
    .fini  :
    {
        PROVIDE(__fini_start = .);
        
        /*PROTECTED REGION ID(Protection: iROM .fini.begin) ENABLED START*/
            /*Protection-Area for your own LDF-Code*/
        /*PROTECTED REGION END*/
        
        KEEP(*(.fini)) /*Code executed before exiting program*/ 
        KEEP(*(.fini*))
        
        /*PROTECTED REGION ID(Protection: iROM .fini) ENABLED START*/
            /*Protection-Area for your own LDF-Code*/
        /*PROTECTED REGION END*/
        
        PROVIDE(__fini_end = .);
        . = ALIGN(8);
        
    } > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */
    
	/*
	 * Exception handling frame for C++ exceptions
	 */
	.eh_frame  :
	{
		PROVIDE(__eh_frame_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .eh_frame.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.eh_frame) /*Exception handling frame for C++ exceptions*/ 
		*(.eh_frame*)
		
		/*PROTECTED REGION ID(Protection: iROM .eh_frame) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__eh_frame_end = .);
		. = ALIGN(8);
		
	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	

	/*Absolute Data-Sections*/
	
	/*
	 * Initialised data addressed as absolute
	 */
	.zdata  :
	{
		PROVIDE(__zdata_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .zdata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.zdata) /*Initialised data addressed as absolute*/ 
		*(.zdata*)
		*(.zdata.rodata) /*absolute addressable readonly data*/ 
		*(.zdata.rodata*)
		*(.zrodata) /*absolute addressable readonly data*/ 
		*(.zrodata*)
		*(.gnu.linkonce.z.*)
		*(.gnu.linkonce.zr.*)
		
		/*PROTECTED REGION ID(Protection: iROM .zdata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__zdata_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	
	/*
	 * Not initialised data addressed as absolute
	 */
	.zbss (NOLOAD) :
	{
		PROVIDE(__zbss_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .zbss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.zbss) /*Not Initialised data addressed as absolute*/ 
		*(.zbss*)
		*(.gnu.linkonce.zb.*)
		
		/*PROTECTED REGION ID(Protection: iROM .zbss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__zbss_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */ 
	
	/*
	 * Not initialised bit data
	 */
	.bbss (NOLOAD) :
	{
		PROVIDE(__bbss_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .bbss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.bbss) /*Not initialised bit data*/ 
		*(.bbss*)
		
		/*PROTECTED REGION ID(Protection: iROM .bbss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__bbss_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */ 
	
	/*
	 * Bit variables
	 */
	.bdata  :
	{
		PROVIDE(__bdata_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .bdata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.bdata) /*Bit variables*/ 
		*(.bdata*)
		
		/*PROTECTED REGION ID(Protection: iROM .bdata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__bdata_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	


	/*Small Data-Sections*/
	
	/*
	 * Storage of write-protected data addressed as small
	 */
	.sdata2  :
	{
		PROVIDE(__sdata2_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .sdata2.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.sdata.rodata) /*Storage of write-protected data addressed as small*/ 
		*(.sdata.rodata*)
		*(.gnu.linkonce.sr.*)
		
		/*PROTECTED REGION ID(Protection: iROM .sdata2) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__sdata2_end = .);
		. = ALIGN(8);
		
	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	
	_SMALL_DATA2_ = SIZEOF(.sdata2) ? ADDR(.sdata2) + 32k : (ADDR(.sdata2) & 0xF0000000) + 32k ;
    __A1_MEM = _SMALL_DATA2_;
	
	/*
	 * Section stores initialised data which is addressable by small data area pointer (%a0)
	 */
	.sdata  :
	{
		PROVIDE(__sdata_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .sdata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.sdata) /*Section stores initialised data which is addressable by small data area pointer (%a0)*/ 
		*(.sdata*)
		*(.gnu.linkonce.s.*)
		
		/*PROTECTED REGION ID(Protection: iROM .sdata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__sdata_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	
	_SMALL_DATA_ = SIZEOF(.sdata) ? ADDR(.sdata) + 32k : (ADDR(.sdata) & 0xF0000000) + 32k ;
    __A0_MEM = _SMALL_DATA_;
	
	/*
	 * Not initialised data in section 閳ワ拷.sbss閳ワ拷, addressable by small data area pointer (%a0)
	 */
	.sbss (NOLOAD) :
	{
		PROVIDE(__sbss_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .sbss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.sbss) /*Not initialised data in section 閳ワ拷.sbss閳ワ拷, addressable by small data area pointer (%a0)*/ 
		*(.sbss*)
		*(.gnu.linkonce.sb.*)
		
		/*PROTECTED REGION ID(Protection: iROM .sbss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__sbss_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */ 
	


	/*Normal Data-Sections*/
	
	/*
	 * Storage of write-protected data
	 */
	.rodata  :
	{
		PROVIDE(__rodata_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .rodata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.rodata) /*Storage of write-protected data*/ 
		*(.rodata*)
		*(.gnu.linkonce.r.*)
		*(.jcr.*)
		
		/*PROTECTED REGION ID(Protection: iROM .rodata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__rodata_end = .);
		. = ALIGN(8);
		
	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	
	/*
	 * Initialised data
	 */
	.data  :
	{
		PROVIDE(__data_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .data.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.data) /*Initialised data*/ 
		*(.data*)
		*(.gnu.linkonce.d.*)
		
		/*PROTECTED REGION ID(Protection: iROM .data) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__data_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	
	/*
	 * Not Initialised data
	 */
	.bss (NOLOAD) :
	{
		PROVIDE(__bss_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .bss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		*(.bss) /*Not Initialised data*/ 
		*(.bss*)
		*(.gnu.linkonce.b.*)
		
		/*PROTECTED REGION ID(Protection: iROM .bss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__bss_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */ 
	
	

	/*PCP-Sections*/
	
	/*
	 * PCP code section
	 */
	.pcptext  :
	{
		PROVIDE(__pcptext_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .pcptext.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		
		/*PROTECTED REGION ID(Protection: iROM .pcptext) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__pcptext_end = .);
		. = ALIGN(8);
		
	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	 
	/*
	 * PCP data section
	 */
	.pcpdata  :
	{
		PROVIDE(__pcpdata_start = .);
		
		/*PROTECTED REGION ID(Protection: iROM .pcpdata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		
		/*PROTECTED REGION ID(Protection: iROM .pcpdata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		
		PROVIDE(__pcpdata_end = .);
		. = ALIGN(8);
		
	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	 

	 
	 
	/*
	 * Section for constructors
	 */
	.ctors          :
	{
		__CTOR_LIST__ = . ;

		/*PROTECTED REGION ID(Protection: iROMconstructor.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2);
		KEEP (*crtbegin.o(.ctors))
		KEEP (*(EXCLUDE_FILE (*crtend.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
		LONG(0) ;
		/*PROTECTED REGION ID(Protection: iROMconstructor) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		__CTOR_END__ = . ;
		 . = ALIGN(8);
	}  > PMU_PFLASH0


	/*
	 * Section for destructors
	 */
	.dtors          :
	{
		__DTOR_LIST__ = . ;
		/*PROTECTED REGION ID(Protection: iROM destructor.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2);
		KEEP (*crtbegin.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
		LONG(0) ;
		/*PROTECTED REGION ID(Protection: iROM destructor) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		__DTOR_END__ = . ;
		. = ALIGN(8);
	} > PMU_PFLASH0
	
	
	/*
	 * Section for clear table
	 */
	.clear_sec :
	{
		. = ALIGN(8);
		PROVIDE(__clear_table = .) ;
			LONG(0 + ADDR(.bss));	LONG(SIZEOF(.bss));
			LONG(0 + ADDR(.sbss));	LONG(SIZEOF(.sbss));
			LONG(0 + ADDR(.zbss));	LONG(SIZEOF(.zbss));
			LONG(0 + ADDR(.bbss));	LONG(SIZEOF(.bbss));
			LONG(0 + ADDR(.diag_data));  LONG(SIZEOF(.diag_data));
			LONG(0 + ADDR(.runpar_data));  LONG(SIZEOF(.runpar_data));
			/*PROTECTED REGION ID(Protection: iROM clear section) ENABLED START*/
				/*Protection-Area for your own LDF-Code*/
			/*PROTECTED REGION END*/
			LONG(-1);                 LONG(-1);
	} > PMU_CLEARTAB
	 
	/*
	* Section for copy table
	*/	
	.copy_sec :
	{
		. = ALIGN(8);
		PROVIDE(__copy_table = .) ;
			LONG(LOADADDR(.data));	LONG(0 + ADDR(.data));	LONG(SIZEOF(.data));
			LONG(LOADADDR(.sdata));	LONG(0 + ADDR(.sdata));	LONG(SIZEOF(.sdata));
			LONG(LOADADDR(.zdata));	LONG(0 + ADDR(.zdata));	LONG(SIZEOF(.zdata));
			LONG(LOADADDR(.bdata));	LONG(0 + ADDR(.bdata));	LONG(SIZEOF(.bdata));
			/*PROTECTED REGION ID(Protection: iROM copy section) ENABLED START*/
				/*Protection-Area for your own LDF-Code*/
			LONG(LOADADDR(.runinfo_data));  LONG(0 + ADDR(.runinfo_data)); LONG(SIZEOF(.runinfo_data));
			LONG(LOADADDR(.eol_data));  LONG(0 + ADDR(.eol_data)); LONG(SIZEOF(.eol_data));
			/*PROTECTED REGION END*/
			LONG(-1);                 LONG(-1);                  LONG(-1);
	} > PMU_COPYTAB 
	 
	
	/*
	 * Section for ustack
	 */	
	.ustack :
	{
		. = ALIGN(8);
		 __USTACK_END = . ;
		. += __USTACK_SIZE ;
		. = ALIGN(8);
		 __USTACK = . ;
		 __USTACK_BEGIN = . ;
	} > DMI_USTACK
	
	/*
	 * Section for istack
	 */	
	.istack :
	{
		. = ALIGN(8);
		 __ISTACK_END = . ;
		. += __ISTACK_SIZE ;
		. = ALIGN(8);
		 __ISTACK = . ;
		 __ISTACK_BEGIN = . ;
	} > DMI_ISTACK
	
	/*
	 * Section for heap
	 */	
	.heap :
	{
		. = ALIGN(8);
		 __HEAP_BEGIN = . ;
		 __HEAP = . ;
		. += __HEAP_SIZE ;
		. = ALIGN(8);
		 __HEAP_END = . ;
	} > DMI_HEAP
	
	/*
	 * Section for CSA
	 */	
	.csa :
	{
		. = ALIGN(64);
		 __CSA_BEGIN = . ;
		 __CSA = . ;
		. += __CSA_SIZE ;
		. = ALIGN(64);
		 __CSA_END = . ;
	} > DMI_CSA
	
	
	/*PROTECTED REGION ID(Protection:iROM-User-Sections) ENABLED START*/
		/*Protection-Area for your own LDF-Code*/
	/*PROTECTED REGION END*/
	
	/*
     * Section for trap table
     */
    .trapsection :
    {
        PROVIDE(__traptab_start = .);
        PROVIDE(__TRAPTAB = .);
        
        /*PROTECTED REGION ID(Protection: iROM .traptab.begin) ENABLED START*/
            /*Protection-Area for your own LDF-Code*/
        /*PROTECTED REGION END*/
        
        KEEP(*(.traptab)) /*Section for trap table*/ 
        
        /*PROTECTED REGION ID(Protection: iROM .traptab) ENABLED START*/
            /*Protection-Area for your own LDF-Code*/
        /*PROTECTED REGION END*/
        
        PROVIDE(__traptab_end = .);
        
        KEEP(*(.trapfunction))
        
        . = ALIGN(8);
        
    } > PMU_TRAP /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */ 
	
	/*
	 * Section for interrupt table
	 */	
	.inttab_tc0_000 (__INTVEC0_START + 0x0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_0)); } > PMU_INTVEC
	.inttab_tc0_001 (__INTVEC0_START + 0x20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_1)); } > PMU_INTVEC
	.inttab_tc0_002 (__INTVEC0_START + 0x40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_2)); } > PMU_INTVEC
	.inttab_tc0_003 (__INTVEC0_START + 0x60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_3)); } > PMU_INTVEC
	.inttab_tc0_004 (__INTVEC0_START + 0x80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_4)); } > PMU_INTVEC
	.inttab_tc0_005 (__INTVEC0_START + 0xA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_5)); } > PMU_INTVEC
	.inttab_tc0_006 (__INTVEC0_START + 0xC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_6)); } > PMU_INTVEC
	.inttab_tc0_007 (__INTVEC0_START + 0xE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_7)); } > PMU_INTVEC
	.inttab_tc0_008 (__INTVEC0_START + 0x100) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_8)); } > PMU_INTVEC
	.inttab_tc0_009 (__INTVEC0_START + 0x120) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_9)); } > PMU_INTVEC
	.inttab_tc0_00A (__INTVEC0_START + 0x140) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_10)); } > PMU_INTVEC
	.inttab_tc0_00B (__INTVEC0_START + 0x160) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_11)); } > PMU_INTVEC
	.inttab_tc0_00C (__INTVEC0_START + 0x180) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_12)); } > PMU_INTVEC
	.inttab_tc0_00D (__INTVEC0_START + 0x1A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_13)); } > PMU_INTVEC
	.inttab_tc0_00E (__INTVEC0_START + 0x1C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_14)); } > PMU_INTVEC
	.inttab_tc0_00F (__INTVEC0_START + 0x1E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_15)); } > PMU_INTVEC
	.inttab_tc0_010 (__INTVEC0_START + 0x200) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_16)); } > PMU_INTVEC
	.inttab_tc0_011 (__INTVEC0_START + 0x220) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_17)); } > PMU_INTVEC
	.inttab_tc0_012 (__INTVEC0_START + 0x240) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_18)); } > PMU_INTVEC
	.inttab_tc0_013 (__INTVEC0_START + 0x260) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_19)); } > PMU_INTVEC
	.inttab_tc0_014 (__INTVEC0_START + 0x280) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_20)); } > PMU_INTVEC
	.inttab_tc0_015 (__INTVEC0_START + 0x2A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_21)); } > PMU_INTVEC
	.inttab_tc0_016 (__INTVEC0_START + 0x2C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_22)); } > PMU_INTVEC
	.inttab_tc0_017 (__INTVEC0_START + 0x2E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_23)); } > PMU_INTVEC
	.inttab_tc0_018 (__INTVEC0_START + 0x300) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_24)); } > PMU_INTVEC
	.inttab_tc0_019 (__INTVEC0_START + 0x320) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_25)); } > PMU_INTVEC
	.inttab_tc0_01A (__INTVEC0_START + 0x340) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_26)); } > PMU_INTVEC
	.inttab_tc0_01B (__INTVEC0_START + 0x360) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_27)); } > PMU_INTVEC
	.inttab_tc0_01C (__INTVEC0_START + 0x380) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_28)); } > PMU_INTVEC
	.inttab_tc0_01D (__INTVEC0_START + 0x3A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_29)); } > PMU_INTVEC
	.inttab_tc0_01E (__INTVEC0_START + 0x3C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_30)); } > PMU_INTVEC
	.inttab_tc0_01F (__INTVEC0_START + 0x3E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_31)); } > PMU_INTVEC
	.inttab_tc0_020 (__INTVEC0_START + 0x400) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_32)); } > PMU_INTVEC
	.inttab_tc0_021 (__INTVEC0_START + 0x420) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_33)); } > PMU_INTVEC
	.inttab_tc0_022 (__INTVEC0_START + 0x440) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_34)); } > PMU_INTVEC
	.inttab_tc0_023 (__INTVEC0_START + 0x460) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_35)); } > PMU_INTVEC
	.inttab_tc0_024 (__INTVEC0_START + 0x480) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_36)); } > PMU_INTVEC
	.inttab_tc0_025 (__INTVEC0_START + 0x4A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_37)); } > PMU_INTVEC
	.inttab_tc0_026 (__INTVEC0_START + 0x4C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_38)); } > PMU_INTVEC
	.inttab_tc0_027 (__INTVEC0_START + 0x4E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_39)); } > PMU_INTVEC
	.inttab_tc0_028 (__INTVEC0_START + 0x500) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_40)); } > PMU_INTVEC
	.inttab_tc0_029 (__INTVEC0_START + 0x520) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_41)); } > PMU_INTVEC
	.inttab_tc0_02A (__INTVEC0_START + 0x540) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_42)); } > PMU_INTVEC
	.inttab_tc0_02B (__INTVEC0_START + 0x560) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_43)); } > PMU_INTVEC
	.inttab_tc0_02C (__INTVEC0_START + 0x580) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_44)); } > PMU_INTVEC
	.inttab_tc0_02D (__INTVEC0_START + 0x5A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_45)); } > PMU_INTVEC
	.inttab_tc0_02E (__INTVEC0_START + 0x5C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_46)); } > PMU_INTVEC
	.inttab_tc0_02F (__INTVEC0_START + 0x5E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_47)); } > PMU_INTVEC
	.inttab_tc0_030 (__INTVEC0_START + 0x600) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_48)); } > PMU_INTVEC
	.inttab_tc0_031 (__INTVEC0_START + 0x620) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_49)); } > PMU_INTVEC
	.inttab_tc0_032 (__INTVEC0_START + 0x640) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_50)); } > PMU_INTVEC
	.inttab_tc0_033 (__INTVEC0_START + 0x660) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_51)); } > PMU_INTVEC
	.inttab_tc0_034 (__INTVEC0_START + 0x680) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_52)); } > PMU_INTVEC
	.inttab_tc0_035 (__INTVEC0_START + 0x6A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_53)); } > PMU_INTVEC
	.inttab_tc0_036 (__INTVEC0_START + 0x6C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_54)); } > PMU_INTVEC
	.inttab_tc0_037 (__INTVEC0_START + 0x6E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_55)); } > PMU_INTVEC
	.inttab_tc0_038 (__INTVEC0_START + 0x700) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_56)); } > PMU_INTVEC
	.inttab_tc0_039 (__INTVEC0_START + 0x720) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_57)); } > PMU_INTVEC
	.inttab_tc0_03A (__INTVEC0_START + 0x740) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_58)); } > PMU_INTVEC
	.inttab_tc0_03B (__INTVEC0_START + 0x760) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_59)); } > PMU_INTVEC
	.inttab_tc0_03C (__INTVEC0_START + 0x780) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_60)); } > PMU_INTVEC
	.inttab_tc0_03D (__INTVEC0_START + 0x7A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_61)); } > PMU_INTVEC
	.inttab_tc0_03E (__INTVEC0_START + 0x7C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_62)); } > PMU_INTVEC
	.inttab_tc0_03F (__INTVEC0_START + 0x7E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_63)); } > PMU_INTVEC
	.inttab_tc0_040 (__INTVEC0_START + 0x800) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_64)); } > PMU_INTVEC
	.inttab_tc0_041 (__INTVEC0_START + 0x820) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_65)); } > PMU_INTVEC
	.inttab_tc0_042 (__INTVEC0_START + 0x840) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_66)); } > PMU_INTVEC
	.inttab_tc0_043 (__INTVEC0_START + 0x860) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_67)); } > PMU_INTVEC
	.inttab_tc0_044 (__INTVEC0_START + 0x880) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_68)); } > PMU_INTVEC
	.inttab_tc0_045 (__INTVEC0_START + 0x8A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_69)); } > PMU_INTVEC
	.inttab_tc0_046 (__INTVEC0_START + 0x8C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_70)); } > PMU_INTVEC
	.inttab_tc0_047 (__INTVEC0_START + 0x8E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_71)); } > PMU_INTVEC
	.inttab_tc0_048 (__INTVEC0_START + 0x900) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_72)); } > PMU_INTVEC
	.inttab_tc0_049 (__INTVEC0_START + 0x920) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_73)); } > PMU_INTVEC
	.inttab_tc0_04A (__INTVEC0_START + 0x940) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_74)); } > PMU_INTVEC
	.inttab_tc0_04B (__INTVEC0_START + 0x960) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_75)); } > PMU_INTVEC
	.inttab_tc0_04C (__INTVEC0_START + 0x980) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_76)); } > PMU_INTVEC
	.inttab_tc0_04D (__INTVEC0_START + 0x9A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_77)); } > PMU_INTVEC
	.inttab_tc0_04E (__INTVEC0_START + 0x9C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_78)); } > PMU_INTVEC
	.inttab_tc0_04F (__INTVEC0_START + 0x9E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_79)); } > PMU_INTVEC
	.inttab_tc0_050 (__INTVEC0_START + 0xA00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_80)); } > PMU_INTVEC
	.inttab_tc0_051 (__INTVEC0_START + 0xA20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_81)); } > PMU_INTVEC
	.inttab_tc0_052 (__INTVEC0_START + 0xA40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_82)); } > PMU_INTVEC
	.inttab_tc0_053 (__INTVEC0_START + 0xA60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_83)); } > PMU_INTVEC
	.inttab_tc0_054 (__INTVEC0_START + 0xA80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_84)); } > PMU_INTVEC
	.inttab_tc0_055 (__INTVEC0_START + 0xAA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_85)); } > PMU_INTVEC
	.inttab_tc0_056 (__INTVEC0_START + 0xAC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_86)); } > PMU_INTVEC
	.inttab_tc0_057 (__INTVEC0_START + 0xAE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_87)); } > PMU_INTVEC
	.inttab_tc0_058 (__INTVEC0_START + 0xB00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_88)); } > PMU_INTVEC
	.inttab_tc0_059 (__INTVEC0_START + 0xB20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_89)); } > PMU_INTVEC
	.inttab_tc0_05A (__INTVEC0_START + 0xB40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_90)); } > PMU_INTVEC
	.inttab_tc0_05B (__INTVEC0_START + 0xB60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_91)); } > PMU_INTVEC
	.inttab_tc0_05C (__INTVEC0_START + 0xB80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_92)); } > PMU_INTVEC
	.inttab_tc0_05D (__INTVEC0_START + 0xBA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_93)); } > PMU_INTVEC
	.inttab_tc0_05E (__INTVEC0_START + 0xBC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_94)); } > PMU_INTVEC
	.inttab_tc0_05F (__INTVEC0_START + 0xBE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_95)); } > PMU_INTVEC
	.inttab_tc0_060 (__INTVEC0_START + 0xC00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_96)); } > PMU_INTVEC
	.inttab_tc0_061 (__INTVEC0_START + 0xC20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_97)); } > PMU_INTVEC
	.inttab_tc0_062 (__INTVEC0_START + 0xC40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_98)); } > PMU_INTVEC
	.inttab_tc0_063 (__INTVEC0_START + 0xC60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_99)); } > PMU_INTVEC
	.inttab_tc0_064 (__INTVEC0_START + 0xC80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_100)); } > PMU_INTVEC
	.inttab_tc0_065 (__INTVEC0_START + 0xCA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_101)); } > PMU_INTVEC
	.inttab_tc0_066 (__INTVEC0_START + 0xCC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_102)); } > PMU_INTVEC
	.inttab_tc0_067 (__INTVEC0_START + 0xCE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_103)); } > PMU_INTVEC
	.inttab_tc0_068 (__INTVEC0_START + 0xD00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_104)); } > PMU_INTVEC
	.inttab_tc0_069 (__INTVEC0_START + 0xD20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_105)); } > PMU_INTVEC
	.inttab_tc0_06A (__INTVEC0_START + 0xD40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_106)); } > PMU_INTVEC
	.inttab_tc0_06B (__INTVEC0_START + 0xD60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_107)); } > PMU_INTVEC
	.inttab_tc0_06C (__INTVEC0_START + 0xD80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_108)); } > PMU_INTVEC
	.inttab_tc0_06D (__INTVEC0_START + 0xDA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_109)); } > PMU_INTVEC
	.inttab_tc0_06E (__INTVEC0_START + 0xDC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_110)); } > PMU_INTVEC
	.inttab_tc0_06F (__INTVEC0_START + 0xDE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_111)); } > PMU_INTVEC
	.inttab_tc0_070 (__INTVEC0_START + 0xE00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_112)); } > PMU_INTVEC
	.inttab_tc0_071 (__INTVEC0_START + 0xE20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_113)); } > PMU_INTVEC
	.inttab_tc0_072 (__INTVEC0_START + 0xE40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_114)); } > PMU_INTVEC
	.inttab_tc0_073 (__INTVEC0_START + 0xE60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_115)); } > PMU_INTVEC
	.inttab_tc0_074 (__INTVEC0_START + 0xE80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_116)); } > PMU_INTVEC
	.inttab_tc0_075 (__INTVEC0_START + 0xEA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_117)); } > PMU_INTVEC
	.inttab_tc0_076 (__INTVEC0_START + 0xEC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_118)); } > PMU_INTVEC
	.inttab_tc0_077 (__INTVEC0_START + 0xEE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_119)); } > PMU_INTVEC
	.inttab_tc0_078 (__INTVEC0_START + 0xF00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_120)); } > PMU_INTVEC
	.inttab_tc0_079 (__INTVEC0_START + 0xF20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_121)); } > PMU_INTVEC
	.inttab_tc0_07A (__INTVEC0_START + 0xF40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_122)); } > PMU_INTVEC
	.inttab_tc0_07B (__INTVEC0_START + 0xF60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_123)); } > PMU_INTVEC
	.inttab_tc0_07C (__INTVEC0_START + 0xF80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_124)); } > PMU_INTVEC
	.inttab_tc0_07D (__INTVEC0_START + 0xFA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_125)); } > PMU_INTVEC
	.inttab_tc0_07E (__INTVEC0_START + 0xFC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_126)); } > PMU_INTVEC
	.inttab_tc0_07F (__INTVEC0_START + 0xFE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_127)); } > PMU_INTVEC
	.inttab_tc0_080 (__INTVEC0_START + 0x1000) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_128)); } > PMU_INTVEC
	.inttab_tc0_081 (__INTVEC0_START + 0x1020) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_129)); } > PMU_INTVEC
	.inttab_tc0_082 (__INTVEC0_START + 0x1040) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_130)); } > PMU_INTVEC
	.inttab_tc0_083 (__INTVEC0_START + 0x1060) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_131)); } > PMU_INTVEC
	.inttab_tc0_084 (__INTVEC0_START + 0x1080) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_132)); } > PMU_INTVEC
	.inttab_tc0_085 (__INTVEC0_START + 0x10A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_133)); } > PMU_INTVEC
	.inttab_tc0_086 (__INTVEC0_START + 0x10C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_134)); } > PMU_INTVEC
	.inttab_tc0_087 (__INTVEC0_START + 0x10E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_135)); } > PMU_INTVEC
	.inttab_tc0_088 (__INTVEC0_START + 0x1100) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_136)); } > PMU_INTVEC
	.inttab_tc0_089 (__INTVEC0_START + 0x1120) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_137)); } > PMU_INTVEC
	.inttab_tc0_08A (__INTVEC0_START + 0x1140) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_138)); } > PMU_INTVEC
	.inttab_tc0_08B (__INTVEC0_START + 0x1160) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_139)); } > PMU_INTVEC
	.inttab_tc0_08C (__INTVEC0_START + 0x1180) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_140)); } > PMU_INTVEC
	.inttab_tc0_08D (__INTVEC0_START + 0x11A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_141)); } > PMU_INTVEC
	.inttab_tc0_08E (__INTVEC0_START + 0x11C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_142)); } > PMU_INTVEC
	.inttab_tc0_08F (__INTVEC0_START + 0x11E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_143)); } > PMU_INTVEC
	.inttab_tc0_090 (__INTVEC0_START + 0x1200) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_144)); } > PMU_INTVEC
	.inttab_tc0_091 (__INTVEC0_START + 0x1220) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_145)); } > PMU_INTVEC
	.inttab_tc0_092 (__INTVEC0_START + 0x1240) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_146)); } > PMU_INTVEC
	.inttab_tc0_093 (__INTVEC0_START + 0x1260) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_147)); } > PMU_INTVEC
	.inttab_tc0_094 (__INTVEC0_START + 0x1280) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_148)); } > PMU_INTVEC
	.inttab_tc0_095 (__INTVEC0_START + 0x12A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_149)); } > PMU_INTVEC
	.inttab_tc0_096 (__INTVEC0_START + 0x12C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_150)); } > PMU_INTVEC
	.inttab_tc0_097 (__INTVEC0_START + 0x12E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_151)); } > PMU_INTVEC
	.inttab_tc0_098 (__INTVEC0_START + 0x1300) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_152)); } > PMU_INTVEC
	.inttab_tc0_099 (__INTVEC0_START + 0x1320) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_153)); } > PMU_INTVEC
	.inttab_tc0_09A (__INTVEC0_START + 0x1340) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_154)); } > PMU_INTVEC
	.inttab_tc0_09B (__INTVEC0_START + 0x1360) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_155)); } > PMU_INTVEC
	.inttab_tc0_09C (__INTVEC0_START + 0x1380) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_156)); } > PMU_INTVEC
	.inttab_tc0_09D (__INTVEC0_START + 0x13A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_157)); } > PMU_INTVEC
	.inttab_tc0_09E (__INTVEC0_START + 0x13C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_158)); } > PMU_INTVEC
	.inttab_tc0_09F (__INTVEC0_START + 0x13E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_159)); } > PMU_INTVEC
	.inttab_tc0_0A0 (__INTVEC0_START + 0x1400) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_160)); } > PMU_INTVEC
	.inttab_tc0_0A1 (__INTVEC0_START + 0x1420) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_161)); } > PMU_INTVEC
	.inttab_tc0_0A2 (__INTVEC0_START + 0x1440) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_162)); } > PMU_INTVEC
	.inttab_tc0_0A3 (__INTVEC0_START + 0x1460) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_163)); } > PMU_INTVEC
	.inttab_tc0_0A4 (__INTVEC0_START + 0x1480) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_164)); } > PMU_INTVEC
	.inttab_tc0_0A5 (__INTVEC0_START + 0x14A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_165)); } > PMU_INTVEC
	.inttab_tc0_0A6 (__INTVEC0_START + 0x14C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_166)); } > PMU_INTVEC
	.inttab_tc0_0A7 (__INTVEC0_START + 0x14E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_167)); } > PMU_INTVEC
	.inttab_tc0_0A8 (__INTVEC0_START + 0x1500) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_168)); } > PMU_INTVEC
	.inttab_tc0_0A9 (__INTVEC0_START + 0x1520) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_169)); } > PMU_INTVEC
	.inttab_tc0_0AA (__INTVEC0_START + 0x1540) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_170)); } > PMU_INTVEC
	.inttab_tc0_0AB (__INTVEC0_START + 0x1560) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_171)); } > PMU_INTVEC
	.inttab_tc0_0AC (__INTVEC0_START + 0x1580) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_172)); } > PMU_INTVEC
	.inttab_tc0_0AD (__INTVEC0_START + 0x15A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_173)); } > PMU_INTVEC
	.inttab_tc0_0AE (__INTVEC0_START + 0x15C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_174)); } > PMU_INTVEC
	.inttab_tc0_0AF (__INTVEC0_START + 0x15E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_175)); } > PMU_INTVEC
	.inttab_tc0_0B0 (__INTVEC0_START + 0x1600) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_176)); } > PMU_INTVEC
	.inttab_tc0_0B1 (__INTVEC0_START + 0x1620) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_177)); } > PMU_INTVEC
	.inttab_tc0_0B2 (__INTVEC0_START + 0x1640) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_178)); } > PMU_INTVEC
	.inttab_tc0_0B3 (__INTVEC0_START + 0x1660) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_179)); } > PMU_INTVEC
	.inttab_tc0_0B4 (__INTVEC0_START + 0x1680) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_180)); } > PMU_INTVEC
	.inttab_tc0_0B5 (__INTVEC0_START + 0x16A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_181)); } > PMU_INTVEC
	.inttab_tc0_0B6 (__INTVEC0_START + 0x16C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_182)); } > PMU_INTVEC
	.inttab_tc0_0B7 (__INTVEC0_START + 0x16E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_183)); } > PMU_INTVEC
	.inttab_tc0_0B8 (__INTVEC0_START + 0x1700) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_184)); } > PMU_INTVEC
	.inttab_tc0_0B9 (__INTVEC0_START + 0x1720) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_185)); } > PMU_INTVEC
	.inttab_tc0_0BA (__INTVEC0_START + 0x1740) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_186)); } > PMU_INTVEC
	.inttab_tc0_0BB (__INTVEC0_START + 0x1760) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_187)); } > PMU_INTVEC
	.inttab_tc0_0BC (__INTVEC0_START + 0x1780) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_188)); } > PMU_INTVEC
	.inttab_tc0_0BD (__INTVEC0_START + 0x17A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_189)); } > PMU_INTVEC
	.inttab_tc0_0BE (__INTVEC0_START + 0x17C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_190)); } > PMU_INTVEC
	.inttab_tc0_0BF (__INTVEC0_START + 0x17E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_191)); } > PMU_INTVEC
	.inttab_tc0_0C0 (__INTVEC0_START + 0x1800) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_192)); } > PMU_INTVEC
	.inttab_tc0_0C1 (__INTVEC0_START + 0x1820) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_193)); } > PMU_INTVEC
	.inttab_tc0_0C2 (__INTVEC0_START + 0x1840) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_194)); } > PMU_INTVEC
	.inttab_tc0_0C3 (__INTVEC0_START + 0x1860) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_195)); } > PMU_INTVEC
	.inttab_tc0_0C4 (__INTVEC0_START + 0x1880) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_196)); } > PMU_INTVEC
	.inttab_tc0_0C5 (__INTVEC0_START + 0x18A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_197)); } > PMU_INTVEC
	.inttab_tc0_0C6 (__INTVEC0_START + 0x18C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_198)); } > PMU_INTVEC
	.inttab_tc0_0C7 (__INTVEC0_START + 0x18E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_199)); } > PMU_INTVEC
	.inttab_tc0_0C8 (__INTVEC0_START + 0x1900) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_200)); } > PMU_INTVEC
	.inttab_tc0_0C9 (__INTVEC0_START + 0x1920) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_201)); } > PMU_INTVEC
	.inttab_tc0_0CA (__INTVEC0_START + 0x1940) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_202)); } > PMU_INTVEC
	.inttab_tc0_0CB (__INTVEC0_START + 0x1960) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_203)); } > PMU_INTVEC
	.inttab_tc0_0CC (__INTVEC0_START + 0x1980) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_204)); } > PMU_INTVEC
	.inttab_tc0_0CD (__INTVEC0_START + 0x19A0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_205)); } > PMU_INTVEC
	.inttab_tc0_0CE (__INTVEC0_START + 0x19C0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_206)); } > PMU_INTVEC
	.inttab_tc0_0CF (__INTVEC0_START + 0x19E0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_207)); } > PMU_INTVEC
	.inttab_tc0_0D0 (__INTVEC0_START + 0x1A00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_208)); } > PMU_INTVEC
	.inttab_tc0_0D1 (__INTVEC0_START + 0x1A20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_209)); } > PMU_INTVEC
	.inttab_tc0_0D2 (__INTVEC0_START + 0x1A40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_210)); } > PMU_INTVEC
	.inttab_tc0_0D3 (__INTVEC0_START + 0x1A60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_211)); } > PMU_INTVEC
	.inttab_tc0_0D4 (__INTVEC0_START + 0x1A80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_212)); } > PMU_INTVEC
	.inttab_tc0_0D5 (__INTVEC0_START + 0x1AA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_213)); } > PMU_INTVEC
	.inttab_tc0_0D6 (__INTVEC0_START + 0x1AC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_214)); } > PMU_INTVEC
	.inttab_tc0_0D7 (__INTVEC0_START + 0x1AE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_215)); } > PMU_INTVEC
	.inttab_tc0_0D8 (__INTVEC0_START + 0x1B00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_216)); } > PMU_INTVEC
	.inttab_tc0_0D9 (__INTVEC0_START + 0x1B20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_217)); } > PMU_INTVEC
	.inttab_tc0_0DA (__INTVEC0_START + 0x1B40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_218)); } > PMU_INTVEC
	.inttab_tc0_0DB (__INTVEC0_START + 0x1B60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_219)); } > PMU_INTVEC
	.inttab_tc0_0DC (__INTVEC0_START + 0x1B80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_220)); } > PMU_INTVEC
	.inttab_tc0_0DD (__INTVEC0_START + 0x1BA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_221)); } > PMU_INTVEC
	.inttab_tc0_0DE (__INTVEC0_START + 0x1BC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_222)); } > PMU_INTVEC
	.inttab_tc0_0DF (__INTVEC0_START + 0x1BE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_223)); } > PMU_INTVEC
	.inttab_tc0_0E0 (__INTVEC0_START + 0x1C00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_224)); } > PMU_INTVEC
	.inttab_tc0_0E1 (__INTVEC0_START + 0x1C20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_225)); } > PMU_INTVEC
	.inttab_tc0_0E2 (__INTVEC0_START + 0x1C40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_226)); } > PMU_INTVEC
	.inttab_tc0_0E3 (__INTVEC0_START + 0x1C60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_227)); } > PMU_INTVEC
	.inttab_tc0_0E4 (__INTVEC0_START + 0x1C80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_228)); } > PMU_INTVEC
	.inttab_tc0_0E5 (__INTVEC0_START + 0x1CA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_229)); } > PMU_INTVEC
	.inttab_tc0_0E6 (__INTVEC0_START + 0x1CC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_230)); } > PMU_INTVEC
	.inttab_tc0_0E7 (__INTVEC0_START + 0x1CE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_231)); } > PMU_INTVEC
	.inttab_tc0_0E8 (__INTVEC0_START + 0x1D00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_232)); } > PMU_INTVEC
	.inttab_tc0_0E9 (__INTVEC0_START + 0x1D20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_233)); } > PMU_INTVEC
	.inttab_tc0_0EA (__INTVEC0_START + 0x1D40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_234)); } > PMU_INTVEC
	.inttab_tc0_0EB (__INTVEC0_START + 0x1D60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_235)); } > PMU_INTVEC
	.inttab_tc0_0EC (__INTVEC0_START + 0x1D80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_236)); } > PMU_INTVEC
	.inttab_tc0_0ED (__INTVEC0_START + 0x1DA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_237)); } > PMU_INTVEC
	.inttab_tc0_0EE (__INTVEC0_START + 0x1DC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_238)); } > PMU_INTVEC
	.inttab_tc0_0EF (__INTVEC0_START + 0x1DE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_239)); } > PMU_INTVEC
	.inttab_tc0_0F0 (__INTVEC0_START + 0x1E00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_240)); } > PMU_INTVEC
	.inttab_tc0_0F1 (__INTVEC0_START + 0x1E20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_241)); } > PMU_INTVEC
	.inttab_tc0_0F2 (__INTVEC0_START + 0x1E40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_242)); } > PMU_INTVEC
	.inttab_tc0_0F3 (__INTVEC0_START + 0x1E60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_243)); } > PMU_INTVEC
	.inttab_tc0_0F4 (__INTVEC0_START + 0x1E80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_244)); } > PMU_INTVEC
	.inttab_tc0_0F5 (__INTVEC0_START + 0x1EA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_245)); } > PMU_INTVEC
	.inttab_tc0_0F6 (__INTVEC0_START + 0x1EC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_246)); } > PMU_INTVEC
	.inttab_tc0_0F7 (__INTVEC0_START + 0x1EE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_247)); } > PMU_INTVEC
	.inttab_tc0_0F8 (__INTVEC0_START + 0x1F00) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_248)); } > PMU_INTVEC
	.inttab_tc0_0F9 (__INTVEC0_START + 0x1F20) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_249)); } > PMU_INTVEC
	.inttab_tc0_0FA (__INTVEC0_START + 0x1F40) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_250)); } > PMU_INTVEC
	.inttab_tc0_0FB (__INTVEC0_START + 0x1F60) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_251)); } > PMU_INTVEC
	.inttab_tc0_0FC (__INTVEC0_START + 0x1F80) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_252)); } > PMU_INTVEC
	.inttab_tc0_0FD (__INTVEC0_START + 0x1FA0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_253)); } > PMU_INTVEC
	.inttab_tc0_0FE (__INTVEC0_START + 0x1FC0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_254)); } > PMU_INTVEC
	.inttab_tc0_0FF (__INTVEC0_START + 0x1FE0) : { . = ALIGN(8) ;  KEEP (*(.intvec_tc0_255)); } > PMU_INTVEC
	__INTTAB = __INTVEC0_START; 
}

