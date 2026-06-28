#include <crow.h>

int main()
{
    crow::mustache::set_global_base("../templates");

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([] {
        auto page = crow::mustache::load("home.html");
        return page.render();
    });

    CROW_ROUTE(app, "/project")([] {
        auto page = crow::mustache::load("project.html");
        return page.render();
    });

    CROW_ROUTE(app, "/about")([] {
        auto page = crow::mustache::load("about.html");
        return page.render();
    });

    app.port(18080).multithreaded().run();
}