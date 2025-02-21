#pragma once

#include <QTimer>
#include <QWidget>

#include "client/kimaiclient.h"
#include "context/kemaisession.h"

namespace Ui {
class ActivityWidget;
}

namespace kemai {

class ActivityWidget : public QWidget
{
    Q_OBJECT

public:
    ActivityWidget(QWidget* parent = nullptr);
    ~ActivityWidget() override;

    void setKemaiSession(std::shared_ptr<KemaiSession> kemaiSession);

signals:
    void currentActivityChanged(bool started);

private:
    void onCbCustomerTextChanged(const QString& text);
    void onCbProjectTextChanged(const QString& text);
    void onCbActivityTextChanged(const QString& text);

    void onTbAddCustomerClicked();
    void onTbAddProjectClicked();
    void onTbAddActivityClicked();

    void onBtStartStopClicked();

    void onSecondTimeout();

    void onSessionCurrentTimeSheetChanged();

    void updateControls();

    void processCustomersResult(CustomersResult customersResult);
    void processProjectsResult(ProjectsResult projectsResult);
    void processActivitiesResult(ActivitiesResult activitiesResult);

    Ui::ActivityWidget* mUi;
    QTimer mSecondTimer;
    std::shared_ptr<KemaiSession> mSession;
};

} // namespace kemai
