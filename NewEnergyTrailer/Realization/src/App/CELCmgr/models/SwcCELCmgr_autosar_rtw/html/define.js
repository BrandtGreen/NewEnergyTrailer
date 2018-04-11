function CodeDefine() { 
this.def = new Array();
this.def["SwcCELCmgr_InactiveUsageMode"] = {file: "SwcCELCmgr_c.html",line:60,type:"fcn"};
this.def["SwcCELCmgr_SystemEgyCalc"] = {file: "SwcCELCmgr_c.html",line:88,type:"fcn"};
this.def["B_SwcCELCmgr_T"] = {file: "SwcCELCmgr_h.html",line:35,type:"type"};
this.def["DW_SwcCELCmgr_T"] = {file: "SwcCELCmgr_h.html",line:45,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:46,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:47,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:81,type:"type"};
this.def["uint8"] = {file: "rtwtypes_h.html",line:84,type:"type"};
this.def["uint16"] = {file: "rtwtypes_h.html",line:85,type:"type"};
this.def["uint32"] = {file: "rtwtypes_h.html",line:86,type:"type"};
this.def["boolean"] = {file: "rtwtypes_h.html",line:87,type:"type"};
this.def["boolean"] = {file: "Platform_Types_h.html",line:17,type:"type"};
this.def["sint16"] = {file: "Platform_Types_h.html",line:18,type:"type"};
this.def["sint32"] = {file: "Platform_Types_h.html",line:19,type:"type"};
this.def["sint8"] = {file: "Platform_Types_h.html",line:20,type:"type"};
this.def["uint16"] = {file: "Platform_Types_h.html",line:21,type:"type"};
this.def["uint32"] = {file: "Platform_Types_h.html",line:22,type:"type"};
this.def["uint8"] = {file: "Platform_Types_h.html",line:23,type:"type"};
this.def["Rte_CData_CELCmgr_TEgyChkTime_5min_data"] = {file: "Rte_SwcCELCmgr_c.html",line:15,type:"var"};
this.def["Rte_CData_CELCmgr_TEgyChkTime_5min"] = {file: "Rte_SwcCELCmgr_c.html",line:16,type:"fcn"};
this.def["Rte_CData_CELCmgr_EgyClimaAllwdFac_data"] = {file: "Rte_SwcCELCmgr_c.html",line:21,type:"var"};
this.def["Rte_CData_CELCmgr_EgyClimaAllwdFac"] = {file: "Rte_SwcCELCmgr_c.html",line:22,type:"fcn"};
this.def["Rte_CData_CELCmgr_EgyCnsAllwdForClimaMax_data"] = {file: "Rte_SwcCELCmgr_c.html",line:27,type:"var"};
this.def["Rte_CData_CELCmgr_EgyCnsAllwdForClimaMax"] = {file: "Rte_SwcCELCmgr_c.html",line:28,type:"fcn"};
this.def["Rte_CData_CELCmgr_TclimaMax_data"] = {file: "Rte_SwcCELCmgr_c.html",line:33,type:"var"};
this.def["Rte_CData_CELCmgr_TclimaMax"] = {file: "Rte_SwcCELCmgr_c.html",line:34,type:"fcn"};
this.def["UInt16"] = {file: "Rte_Type_h.html",line:31,type:"type"};
this.def["UInt8"] = {file: "Rte_Type_h.html",line:32,type:"type"};
this.def["Rte_Instance"] = {file: "Rte_Type_h.html",line:33,type:"type"};
this.def["Std_ReturnType"] = {file: "Std_Types_h.html",line:17,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["SwcCELCmgr_c.html"] = "../SwcCELCmgr.c";
	this.html2Root["SwcCELCmgr_c.html"] = "SwcCELCmgr_c.html";
	this.html2SrcPath["SwcCELCmgr_h.html"] = "../SwcCELCmgr.h";
	this.html2Root["SwcCELCmgr_h.html"] = "SwcCELCmgr_h.html";
	this.html2SrcPath["SwcCELCmgr_private_h.html"] = "../SwcCELCmgr_private.h";
	this.html2Root["SwcCELCmgr_private_h.html"] = "SwcCELCmgr_private_h.html";
	this.html2SrcPath["SwcCELCmgr_types_h.html"] = "../SwcCELCmgr_types.h";
	this.html2Root["SwcCELCmgr_types_h.html"] = "SwcCELCmgr_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["SwcCELCmgr_arxml.html"] = "../SwcCELCmgr.arxml";
	this.html2Root["SwcCELCmgr_arxml.html"] = "SwcCELCmgr_arxml.html";
	this.html2SrcPath["Compiler_h.html"] = "../stub/Compiler.h";
	this.html2Root["Compiler_h.html"] = "Compiler_h.html";
	this.html2SrcPath["Platform_Types_h.html"] = "../stub/Platform_Types.h";
	this.html2Root["Platform_Types_h.html"] = "Platform_Types_h.html";
	this.html2SrcPath["Rte_SwcCELCmgr_c.html"] = "../stub/Rte_SwcCELCmgr.c";
	this.html2Root["Rte_SwcCELCmgr_c.html"] = "Rte_SwcCELCmgr_c.html";
	this.html2SrcPath["Rte_SwcCELCmgr_h.html"] = "../stub/Rte_SwcCELCmgr.h";
	this.html2Root["Rte_SwcCELCmgr_h.html"] = "Rte_SwcCELCmgr_h.html";
	this.html2SrcPath["Rte_Type_h.html"] = "../stub/Rte_Type.h";
	this.html2Root["Rte_Type_h.html"] = "Rte_Type_h.html";
	this.html2SrcPath["Std_Types_h.html"] = "../stub/Std_Types.h";
	this.html2Root["Std_Types_h.html"] = "Std_Types_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"SwcCELCmgr_c.html","SwcCELCmgr_h.html","SwcCELCmgr_private_h.html","SwcCELCmgr_types_h.html","rtwtypes_h.html","SwcCELCmgr_arxml.html","Compiler_h.html","Platform_Types_h.html","Rte_SwcCELCmgr_c.html","Rte_SwcCELCmgr_h.html","Rte_Type_h.html","Std_Types_h.html"];
