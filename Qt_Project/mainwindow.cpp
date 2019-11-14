#include "mainwindow.h"
#include "numerical_solutions.cpp"
#include "qcustomplot.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->lbl_func_inv->setVisible(false);
    ui->lbl_err_inv->setVisible(false);
    ui->func_plot->legend->setVisible(true);
    ui->func_plot->replot();
    ui->err_plot->legend->setVisible(true);
    ui->err_plot->replot();
}

MainWindow::~MainWindow() { delete ui; }

MainWindow::real MainWindow::f(MainWindow::real x, MainWindow::real y) {
    return y * y * std::exp(x) - 2.0 * y;
}

MainWindow::real MainWindow::y(MainWindow::real x, MainWindow::point p0) {
    real x0 = p0.first, y0 = p0.second;
    real c = (std::exp(-x0) / y0 - 1) / std::exp(x0);
    return std::exp(-x) / (c * std::exp(x) + 1);
}

void MainWindow::func_add_numerical_method(ode_solver *slv,
                                           MainWindow::point p0,
                                           MainWindow::real xlim,
                                           unsigned int prec, std::string name,
                                           QColor color) {

    std::vector<point> points = slv->solve_interval(f, p0, xlim, prec);

    QVector<real> xdat(points.size()), ydat(points.size());
    for (int i = 0; i < points.size(); i++)
        xdat[i] = points[i].first, ydat[i] = points[i].second;

    ui->func_plot->addGraph();
    ui->func_plot->graph()->setPen(QPen(color));
    ui->func_plot->graph()->setData(xdat, ydat);
    ui->func_plot->graph()->setName(QString::fromStdString(name));
    if (points.size() < 50)
        ui->func_plot->graph()->setScatterStyle(
            QCPScatterStyle(QCPScatterStyle::ssCircle, color, Qt::white, 5));
}

void MainWindow::func_add_numerical_method_le(ode_solver *slv,
                                              MainWindow::point p0,
                                              MainWindow::real xlim,
                                              unsigned int prec,
                                              std::string name, QColor color) {
    std::vector<point> points = slv->solve_interval(f, p0, xlim, prec);

    QVector<real> xdat(points.size()), ydat(points.size());
    for (int i = 0; i < points.size(); i++)
        xdat[i] = points[i].first, ydat[i] = points[i].second;

    QVector<real> eydat(xdat.size());
    for (int i = 0; i < xdat.size(); i++)
        eydat[i] = y(xdat[i], p0) - ydat[i];
    ui->func_plot->addGraph();
    ui->func_plot->graph()->setPen(QPen(color));
    ui->func_plot->graph()->setData(xdat, eydat);
    ui->func_plot->graph()->setName(QString::fromStdString(name));
    ui->func_plot->graph()->setBrush(
        QBrush(QColor(color.red(), color.green(), color.blue(), 20)));
    if (xdat.size() < 50) {
        ui->func_plot->graph()->setScatterStyle(
            QCPScatterStyle(QCPScatterStyle::ssDisc, color, 5));
    }
}

void MainWindow::on_btn_func_plot_clicked() {
    on_btn_func_clear_clicked();

    QString x0s = ui->ln_func_x0->text();
    QString y0s = ui->ln_func_y0->text();
    QString xlims = ui->ln_func_xlim->text();
    QString precs = ui->ln_func_prec->text();

    bool ok_x0, ok_y0, ok_xlim, ok_prec;

    real x0 = x0s.toDouble(&ok_x0);
    real y0 = y0s.toDouble(&ok_y0);
    real xlim = xlims.toDouble(&ok_xlim);
    unsigned int prec = precs.toUInt(&ok_prec);

    if (!ok_x0 || !ok_y0 || !ok_xlim || !ok_prec || xlim < x0 || prec == 0) {
        on_btn_func_clear_clicked();
        ui->lbl_func_inv->setVisible(true);
        return;
    }

    if (ui->chk_func_as->isChecked()) {
        QVector<real> xdat(prec + 1), ydat(prec + 1);
        real dx = (xlim - x0) / prec;

        for (int i = 0; i < prec + 1; i++) {
            xdat[i] = x0 + dx * i;
            ydat[i] = y(xdat[i], point(x0, y0));
        }
        ui->func_plot->addGraph();
        ui->func_plot->graph()->setPen(QPen(Qt::black));
        ui->func_plot->graph()->setData(xdat, ydat);
        ui->func_plot->graph()->setName("Analytical solution");
        if (xdat.size() < 100)
            ui->func_plot->graph()->setScatterStyle(QCPScatterStyle(
                QCPScatterStyle::ssCircle, Qt::black, Qt::white, 5));
    }

    if (ui->chk_func_em->isChecked())
        func_add_numerical_method(&ems, point(x0, y0), xlim, prec,
                                  "Euler method", QColor(255, 0, 0));
    if (ui->chk_func_em_le->isChecked())
        func_add_numerical_method_le(&ems, point(x0, y0), xlim, prec,
                                     "EM local error", QColor(255, 0, 0));

    if (ui->chk_func_iem->isChecked())
        func_add_numerical_method(&iems, point(x0, y0), xlim, prec,
                                  "Improved Euler method", QColor(0, 255, 0));
    if (ui->chk_func_iem_le->isChecked())
        func_add_numerical_method_le(&iems, point(x0, y0), xlim, prec,
                                     "IEM local error", QColor(0, 255, 0));

    if (ui->chk_func_rk->isChecked())
        func_add_numerical_method(&rk4, point(x0, y0), xlim, prec,
                                  "Runge-Kutta method", QColor(0, 0, 255));
    if (ui->chk_func_rk_le->isChecked())
        func_add_numerical_method_le(&rk4, point(x0, y0), xlim, prec,
                                     "RK4 local error", QColor(0, 0, 255));

    ui->func_plot->rescaleAxes(true);

    ui->func_plot->replot();
}

void MainWindow::on_btn_func_clear_clicked() {
    ui->func_plot->clearGraphs();
    ui->func_plot->xAxis->setRange(0, 5);
    ui->func_plot->yAxis->setRange(0, 5);
    ui->func_plot->replot();
    ui->lbl_func_inv->setVisible(false);
}

void MainWindow::err_add_numerical_method(ode_solver *slv, MainWindow::point p0,
                                          MainWindow::real xlim,
                                          unsigned int prec_from,
                                          unsigned int prec_to,
                                          std::string name, QColor color) {
    QVector<real> xdat, ydat;
    for (unsigned int i = prec_from; i <= prec_to; i++) {
        std::vector<point> points = slv->solve_interval(f, p0, xlim, i);
        real dev = 0.0;
        for (auto pnt : points)
            dev += (y(pnt.first, p0) - pnt.second) *
                   (y(pnt.first, p0) - pnt.second) / points.size();
        xdat.push_back(i), ydat.push_back(dev);
    }
    ui->err_plot->addGraph();
    ui->err_plot->graph()->setPen(QPen(color));
    ui->err_plot->graph()->setData(xdat, ydat);
    ui->err_plot->graph()->setName(QString::fromStdString(name));
    if (xdat.size() < 50)
        ui->err_plot->graph()->setScatterStyle(
            QCPScatterStyle(QCPScatterStyle::ssCircle, color, Qt::white, 5));
}

void MainWindow::on_btn_err_plot_clicked() {
    on_btn_err_clear_clicked();

    QString x0s = ui->ln_err_x0->text();
    QString y0s = ui->ln_err_y0->text();
    QString xlims = ui->ln_err_xlim->text();
    QString prec_froms = ui->ln_err_prec_from->text();
    QString prec_tos = ui->ln_err_prec_to->text();

    bool ok_x0, ok_y0, ok_xlim, ok_prec_from, ok_prec_to;

    real x0 = x0s.toDouble(&ok_x0);
    real y0 = y0s.toDouble(&ok_y0);
    real xlim = xlims.toDouble(&ok_xlim);
    unsigned int prec_from = prec_froms.toUInt(&ok_prec_from);
    unsigned int prec_to = prec_tos.toUInt(&ok_prec_to);

    if (!ok_x0 || !ok_y0 || !ok_xlim || !ok_prec_from || !ok_prec_to ||
        xlim < x0 || prec_from == 0 || prec_to < prec_from) {
        on_btn_err_clear_clicked();
        ui->lbl_err_inv->setVisible(true);
        return;
    }

    if (ui->chk_err_em->isChecked())
        err_add_numerical_method(&ems, point(x0, y0), xlim, prec_from, prec_to,
                                 "Euler method", QColor(255, 0, 0));
    if (ui->chk_err_iem->isChecked())
        err_add_numerical_method(&iems, point(x0, y0), xlim, prec_from, prec_to,
                                 "Improved Euler method", QColor(0, 255, 0));
    if (ui->chk_err_rk->isChecked())
        err_add_numerical_method(&rk4, point(x0, y0), xlim, prec_from, prec_to,
                                 "Runge-Kutta method", QColor(0, 0, 255));

    ui->err_plot->rescaleAxes();

    ui->err_plot->replot();
}

void MainWindow::on_btn_err_clear_clicked() {
    ui->err_plot->clearGraphs();
    ui->err_plot->xAxis->setRange(0, 5);
    ui->err_plot->yAxis->setRange(0, 5);
    ui->err_plot->replot();
    ui->lbl_err_inv->setVisible(false);
}
