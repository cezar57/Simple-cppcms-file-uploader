#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_file.h>
#include <iostream>
#include "upload.h"

using namespace::std;
using namespace::cppcms;

class uploader: public cppcms::application {
public:
    uploader(cppcms::service &s) : cppcms::application(s) {}

    void main(string dump)
    {
        content::upload up_var;
        if(request().request_method()=="POST") {
            up_var.info.load(context());
            if(up_var.info.validate()) {
                string new_name = up_var.info.description.value();
                up_var.info.file.value()->save_to("./uploads/" + new_name); 
                up_var.info.clear();
            }
        }
        render("upload",up_var);
    }
};

int main(int argc,char ** argv)
{
    try {
        cppcms::service app(argc,argv);
        app.applications_pool().mount(cppcms::applications_factory<uploader>());
        app.run();
    }
    catch( exception const &e) {
        cerr<<e.what()<<endl;
    }
}
