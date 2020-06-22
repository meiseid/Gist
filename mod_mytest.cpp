#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"
#include "http_log.h"
#include "util_script.h"
#include <string>

/* The sample content handler */
static int mytest_handler(request_rec *r)
{
    if (strcmp(r->handler, "mytest")) {
        return DECLINED;
    }
//    r->content_type = "application/json; charset=utf-8";
    r->content_type = "text/plain; charset=utf-8";

	if (r->header_only){
		return OK;
	}

    ap_rputs("The sample page from mod_mytest.c\n", r);

	std::string s = std::string("てすとばる");

	ap_rprintf(r, "てすときー = [%s]\n", s.c_str());

    return OK;
}

static void mytest_register_hooks(apr_pool_t *p)
{
    ap_hook_handler(mytest_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Dispatch list for API hooks */
extern "C" {

module AP_MODULE_DECLARE_DATA mytest_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    mytest_register_hooks  /* register hooks                      */
};

};
