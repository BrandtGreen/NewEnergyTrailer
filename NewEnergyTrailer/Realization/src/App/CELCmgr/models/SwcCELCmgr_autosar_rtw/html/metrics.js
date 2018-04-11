function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["Rte_CData_CELCmgr_EgyClimaAllwdFac_data"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	size: 1};
	 this.metricsArray.var["Rte_CData_CELCmgr_EgyCnsAllwdForClimaMax_data"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	size: 1};
	 this.metricsArray.var["Rte_CData_CELCmgr_TEgyChkTime_5min_data"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	size: 2};
	 this.metricsArray.var["Rte_CData_CELCmgr_TclimaMax_data"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	size: 1};
	 this.metricsArray.fcn["Rte_CData_SwcCELCmgr_CELCmgr_EgyClimaAllwdFac"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Rte_CData_SwcCELCmgr_CELCmgr_EgyCnsAllwdForClimaMax"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Rte_CData_SwcCELCmgr_CELCmgr_TEgyChkTime_5min"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Rte_CData_SwcCELCmgr_CELCmgr_TclimaMax"] = {file: "D:\\03_Development\\Trailer\\10_VCU_Debug\\01_VehicleControl\\src\\App\\CELCmgr\\models\\SwcCELCmgr_autosar_rtw\\stub\\Rte_SwcCELCmgr.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="SwcCELCmgr_metrics.html">Global Memory: 5(bytes) Maximum Stack: 0(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
