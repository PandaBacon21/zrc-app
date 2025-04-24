#include <crow.h>

int main() {
    crow::SimpleApp app;

    // Will updated moving forward - this is a placeholder for now
    // API will be updated to leverage the zrcsdk to turn on and off the camera 
    CROW_ROUTE(app, "/")([]() {
        return "Welcome to the Zoom Room Controller API!";
    });

    // Start the server
    app.port(8080).multithreaded().run();

    return 0;
}