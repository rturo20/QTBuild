/*
 * Minimal Qt Window Program - Object-Oriented Version
 * 
 * This version uses a custom window class that inherits from QMainWindow.
 * This is a more structured and extensible approach for Qt applications.
 * 
 * Dependencies: Qt5 development libraries
 */

// Qt core application class - required for any Qt GUI app
#include <QApplication>
// Main window class - provides standard window functionality
#include <QMainWindow>

/**
 * CustomWindow Class
 * 
 * A custom window class that inherits from QMainWindow.
 * This allows us to encapsulate all window-specific functionality
 * and makes the code more organized and extensible.
 */
class CustomWindow : public QMainWindow {
public:
    /**
     * Constructor
     * 
     * Initializes the window with default settings.
     * This is where we set up the window's appearance and behavior.
     */
    CustomWindow() {
        // Set the window title
        setWindowTitle("Minimal Qt Window - OOP Version");
        
        // Set the window size to 600x400 pixels
        setFixedSize(600, 400);
        
        // Additional window setup can be added here
        // For example: setWindowIcon(), setStatusBar(), etc.
    }
    
    /**
     * Destructor
     * 
     * Clean up any resources when the window is destroyed.
     * Qt handles most cleanup automatically, but you can add custom cleanup here.
     */
    ~CustomWindow() {
        // Custom cleanup code can go here if needed
    }
    
    void initializeAndShow() {
        show();
    }
    
    // You can add more methods here for additional functionality
    // For example: void setupMenu(), void setupToolbar(), etc.
};

/**
 * Main function - Program entry point
 * Creates the Qt application and our custom window
 */
int main(int argc, char* argv[]) {
    // Create Qt application object (required for any Qt GUI app)
    QApplication app(argc, argv);
    
    // Create our custom window object
    CustomWindow window;
    
    // Show the window
    window.initializeAndShow();
    
    // Start the event loop (keeps the program running)
    return app.exec();
} 