# faculty-information-management-system
一、定义报账信息（CGReport）类，其中至少包括5个属性（例如名字、金额），至少有三个默认值。  二、定义CGReports动态数组CGReportList，描述任意多的报账信息。三、实现如下基本功能 显示报账信息包括编号、时间（精确到分钟）、部门、姓名、事项、金额、票据照片、状态类别及备注; 报账信息状态类别分为审核和未审两种,审核报账信息后的状态可改为已拨款或未拨款;   四、拓展功能 部长可对所有备注进行修改和删除、审核；职工只能对自己部门的报账备注编辑。 用户设置二个级别，部长，职工；只有部长有权限可以设定另外职工的人数和权限; 每个职工之间的报账信息保密，部长可以查看全部信息; 部长审核之后的报账信息自动发送信息给申报该项目的职工。