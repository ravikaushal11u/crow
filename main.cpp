// #include <crow.h>

// int main()
// {
//     crow::mustache::set_global_base("../templates");

//     crow::SimpleApp app;

//     CROW_ROUTE(app, "/")([] {
//         auto page = crow::mustache::load("home.html");
//         return page.render();
//     });

//     CROW_ROUTE(app, "/project")([] {
//         auto page = crow::mustache::load("project.html");
//         return page.render();
//     });

//     CROW_ROUTE(app, "/about")([] {
//         auto page = crow::mustache::load("about.html");
//         return page.render();
//     });
    
//      CROW_ROUTE(app, "/notes")([] {
//         auto page = crow::mustache::load("notes.html");
//         return page.render();
//     });
//     app.port(18080).multithreaded().run();
// }


// form GET AND POST METHODS

 // get
 // #include <crow.h>

// int main()
// {
//     crow::mustache::set_global_base("../templates");

//     crow::SimpleApp app;

//     CROW_ROUTE(app,"/")
//     ([]{
       
//          return crow::mustache::load("about.html").render(); // get method 
//     });

//     CROW_ROUTE(app,"/search")
//     ([](const crow::request& req){

//         auto name=req.url_params.get("name");

//         if(name)
//             return crow::response("Hello "+std::string(name));

//         return crow::response("Name Missing");

//     });

//     app.port(18080).run();


 
// }


post 

#include <crow.h>
#include <iostream>

int main()
{
    crow::mustache::set_global_base("../templates");

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([] {
        return crow::mustache::load("home.html").render();
    });

    CROW_ROUTE(app, "/login")
    .methods(crow::HTTPMethod::POST)
    ([](const crow::request& req)
    {
        std::cout << "Body: " << req.body << std::endl;

        return crow::response("Form Submitted");
    });

    app.port(18080).multithreaded().run();
}

// CRUD OPERATION
