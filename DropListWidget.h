// DropListWidget.h
#ifndef DROPLISTWIDGET_H
#define DROPLISTWIDGET_H

#include <QListWidget>
#include <QMimeData>
#include <QDropEvent>
#include <QDragEnterEvent>

class DropListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit DropListWidget(QWidget* parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void dropEvent(QDropEvent* event) override;

private:
    bool canDecodeMimeData(const QMimeData* mimeData) const;

signals:
    void filesDropped(const QStringList& filePaths); // 自定义信号，通知主窗口有文件被拖入
};

#endif // DROPLISTWIDGET_H