/**
 * @file display.h
 * Display class for the can-translator program.
 *
 * @author Andrew Mass
 * @date Created: 2014-06-24
 * @date Modified: 2014-07-29
 */
#ifndef APP_DISPLAY_H
#define APP_DISPLAY_H

#include <QFont>
#include <QLabel>
#include <QCheckBox>
#include <QKeyEvent>
#include <QFileDialog>
#include <QHeaderView>
#include <QMessageBox>
#include <QPushButton>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QApplication>
#include <QProgressBar>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "data.h"
#include "config.h"

#define WIDTH 1400
#define HEIGHT 720

/**
 * Class which handles the construction of the GUI and button presses.
 */
class AppDisplay : public QWidget {
  Q_OBJECT

  public:

    /**
     * Default constructor for AppDisplay class. Essentially the main entry
     * point for the entire application.
     */
    AppDisplay();

    /**
     * If true, the configuration scanning process was successful and it is
     * safe to continue to execution of the program.
     */
    bool successful;

  protected:

    /**
     * Called when the user presses a key on their keyboard. Not called
     * when a user presses a key that isn't on their keyboard.
     *
     * @params e The key event that occurred.
     */
    void keyPressEvent(QKeyEvent* e);

  private slots:

    /**
     * Calls the cooresponding readData() method in the data class when
     * btn_read is pressed.
     */
    void readData();

    /**
     * Scans the grid of checkboxes to see which channels the user wants
     * to convert, then returns this info.
     *
     * @returns A map of message IDs to arrays of bools that contains info about which
     *     channels the user selected to be converted.
     */
    map<unsigned short, vector<bool> > getEnabled();

    /**
     * Sets all channel checkboxes as checked.
     */
    void selectAll();

    /**
     * Sets all channel checkboxes as not checked.
     */
    void selectNone();

    /**
     * Displays the error message in a critical error message box.
     *
     * @param error The error message to display.
     */
    void handleError(QString error);

    /**
     * Updates the progress bar with the latest progress counter.
     *
     * @param progress The latest progress counter to display.
     */
    void updateProgress(int progress);

  private:

    /**
     * Sets all channel checkboxes as either checked or not checked.
     *
     * @param checked Whether to set the boxes as checked or not checked.
     */
    void selectBoxes(bool checked);

    AppConfig config;
    AppData data;

    QVBoxLayout layout;
    QVBoxLayout layout_headers;
    QHBoxLayout layout_selects;

    QLabel lbl_header;
    QLabel lbl_subheader;
    QLabel lbl_keymaps;

    QTableWidget table;

    QPushButton btn_read;
    QPushButton btn_select_all;
    QPushButton btn_select_none;

    QProgressBar bar_convert;
};

#endif // APP_DISPLAY_H