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
// Label widget for displaying text and images
// QLabel is one of the most basic Qt widgets for showing content
#include <QLabel>

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
        // Set the window title that appears in the title bar
        setWindowTitle("Qt Window - OOP Version");
        
        // Set the window size to 600x400 pixels (width x height)
        // Fixed size prevents user from resizing the window
        setFixedSize(600, 400);
        
        // Create a QLabel widget to display text on the window
        // QLabel is a simple widget for displaying text or images
        // Parameters: text content, parent widget (this window)
        QLabel* welcomeLabel = new QLabel("WELCOME", this);
        
        // Center-align the text within the label widget
        // Qt::AlignCenter centers both horizontally and vertically
        welcomeLabel->setAlignment(Qt::AlignCenter);
        
        // Apply custom styling to the label using CSS-like syntax
        // This makes the text more visually appealing
        // - font-size: 24px - Sets text size to 24 pixels
        // - font-weight: bold - Makes text bold
        // - color: #2c3e50 - Sets text color to dark blue
        welcomeLabel->setStyleSheet("QLabel { font-size: 24px; font-weight: bold; color:rgb(11, 121, 231); }");
        
        // Set the welcome label as the central widget of the main window
        // This makes the label fill the entire window area
        // QMainWindow requires a central widget to display content
        setCentralWidget(welcomeLabel);
        
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
    
    /**
     * Initialize and display the window
     * 
     * This method makes the window visible to the user.
     * It's called after the window has been fully configured.
     */
    void initializeAndShow() {
        // Display the window on screen
        // This triggers the window to become visible and interactive
        show();
    }
    
    // You can add more methods here for additional functionality
    // For example: void setupMenu(), void setupToolbar(), etc.
};

/**
 * Main function - Program entry point
 * 
 * This is where the program starts execution.
 * It creates the Qt application and our custom window.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return Exit code (0 for success)
 */
int main(int argc, char* argv[]) {
    // Create Qt application object (required for any Qt GUI app)
    // QApplication manages the GUI system and main settings
    // It must be created before any GUI elements
    QApplication app(argc, argv);
    
    // Create our custom window object
    // This calls the CustomWindow constructor which sets up the window
    CustomWindow window;
    
    // Show the window on screen
    // This makes the window visible and starts the user interaction
    window.initializeAndShow();
    
    // Start the Qt event loop (keeps the program running)
    // The event loop handles user input, window events, and application lifecycle
    // This call blocks until the application is closed
    return app.exec();
} 