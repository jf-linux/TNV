// 跟踪服务器
// 定义主函数
//
#include "01_globals.h"
#include "11_server.h"

int main(void) {
	// 初始化ACL库
	acl::acl_cpp_init();
	acl::log::stdout_open(true);

	// 创建并运行服务器
	server_c& server = acl::singleton2<server_c>::get_instance();
	server.set_cfg_str(cfg_str);
	server.set_cfg_int(cfg_int);
	server.run_alone("192.168.65.128:21000", "../etc/tracker.cfg");

	return 0;
}
