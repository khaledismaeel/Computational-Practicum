#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "numerical_solutions.cpp"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_func_plot_clicked();

    void on_btn_func_clear_clicked();

    void on_btn_err_plot_clicked();

    void on_btn_err_clear_clicked();

private:
    typedef double real;
    typedef std::pair<real, real> point;

    euler_method_solver ems;
    improved_euler_method_solver iems;
    RK4_solver rk4;

    static real f(real x, real y);
    static real y(real x, point p0);

    Ui::MainWindow *ui;
    void err_add_numerical_method(ode_solver *slv, MainWindow::point p0,
                                  MainWindow::real xlim, unsigned int prec_from,
                                  unsigned int prec_to, std::string name,
                                  QColor color);
    void func_add_numerical_method(ode_solver *slv, MainWindow::point p0,
                                   MainWindow::real xlim, unsigned int prec,
                                   std::string name, QColor color);
    void func_add_numerical_method_le(ode_solver *slv, MainWindow::point p0,
                                      MainWindow::real xlim, unsigned int prec,
                                      std::string name, QColor color);
};
#endif // MAINWINDOW_H
