#ifndef PATHEDITORWIDGET_H
#define PATHEDITORWIDGET_H

#include "objects.h"

#include <QWidget>
#include <QListWidget>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QLabel>

class PathEditorWidget : public QWidget
{
    Q_OBJECT
public:
    PathEditorWidget(QList<Path*> *paths);
    void deselect();
    void select(PathNode* node);
    void updateEditor();

signals:
    void updateLevelView();
    void selectedPathChanged(Object* pPath);
    void editMade();

public slots:

private:
    Path* editPath;
    PathNode* editNode;
    bool editingAPath = false;
    bool handleChanges = true;

    QList<Path*> *paths;

    QWidget* edits;
    QListWidget* pathList;

    QLabel* currentNode;

    QSpinBox* id;
    QCheckBox* loop;
    QDoubleSpinBox* speed;
    QDoubleSpinBox* acceleration;
    QDoubleSpinBox* delay;

    class HorLine : public QFrame { public: HorLine() { setFrameStyle(QFrame::HLine | QFrame::Sunken); } };

    void updateList();
    void updateInfo();

private slots:
    void handlePathListIndexChanged(QListWidgetItem *item);
    void handleIDChanged(int idVal);
    void handleLoopChanged();
    void handleSpeedChanged(double speedVal);
    void handleAccelChanged(double accelVal);
    void handleDelayChanged(double delayVal);

};

#endif // PATHEDITORWIDGET_H
