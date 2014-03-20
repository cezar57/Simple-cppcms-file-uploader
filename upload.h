#ifndef UPLOAD_H
#define UPLOAD_H
#include <cppcms/view.h>
#include <cppcms/form.h>
#include <iostream>
using namespace::std;
using namespace::cppcms;

namespace content  {
 
struct file_form : public  form {
    widgets::text description;
    widgets::file file;
    widgets::submit submit;
    file_form() {
        file.message("File to upload");
        file.non_empty();
        description.message("Desired File Name:");
        description.non_empty();
        file.limits(0,-1);
        submit.value("Upload");
        add(file);
        add(description);
        add(submit);
    }
};

struct upload : public  base_content {
    file_form info;
};
}

#endif
