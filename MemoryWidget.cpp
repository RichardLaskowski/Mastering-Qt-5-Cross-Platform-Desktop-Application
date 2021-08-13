#include "MemoryWidget.h"
#include "SysInfo.h"
#include <QtCharts/QAreaSeries>
#include <QValueAxis>

using namespace QtCharts;

const int CHART_X_RANGE_COUNT = 50;
const int CHART_X_RANGE_MAX = CHART_X_RANGE_COUNT - 1;

MemoryWidget::MemoryWidget(QWidget *parent) : SysInfoWidget(parent), mSeries(new QLineSeries(this)), mPointPositionX(0)
{
    QAreaSeries* areaSeries = new QAreaSeries(mSeries);

    QChart* chart = chartView().chart();
    chart->addSeries(areaSeries);
    chart->createDefaultAxes();
    chart->setTitle("Memory used");
    chart->axes(Qt::Horizontal).first()->setRange(0, CHART_X_RANGE_MAX);
    chart->axes(Qt::Vertical).first()->setRange(0, 25);
}

void MemoryWidget::updateSeries()
{
    double memoryUsed = SysInfo::instance().memoryUsed();
    mSeries->append(mPointPositionX++, memoryUsed);

    if(mSeries->count() > CHART_X_RANGE_COUNT)
    {
        QChart* chart = chartView().chart();
        chart->scroll(chart->plotArea().width() / CHART_X_RANGE_MAX, 0);
        mSeries->remove(0);
    }
}
