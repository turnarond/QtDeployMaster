// DropListWidget.cpp
#include "DropListWidget.h"
#include <QUrl>

DropListWidget::DropListWidget(QWidget* parent)
    : QListWidget(parent)
{
}

void DropListWidget::dragEnterEvent(QDragEnterEvent* event)
{
    if (canDecodeMimeData(event->mimeData())) {
        event->acceptProposedAction(); // 接受拖拽
    }
    else {
        event->ignore();
    }
}

void DropListWidget::dragMoveEvent(QDragMoveEvent* event)
{
    if (canDecodeMimeData(event->mimeData())) {
        event->acceptProposedAction();
    }
    else {
        event->ignore();
    }
}

void DropListWidget::dropEvent(QDropEvent* event)
{
    if (canDecodeMimeData(event->mimeData())) {
        const QMimeData* mimeData = event->mimeData();
        QStringList filePaths;

        // 从 MIME 数据中提取文件路径
        if (mimeData->hasUrls()) {
            QList<QUrl> urlList = mimeData->urls();
            for (const QUrl& url : urlList) {
                if (url.isLocalFile()) { // 只处理本地文件
                    QString localPath = url.toLocalFile();
                    filePaths.append(localPath);
                }
            }
        }

        if (!filePaths.isEmpty()) {
            emit filesDropped(filePaths); // 发射信号
            event->acceptProposedAction();
        }
        else {
            event->ignore();
        }
    }
    else {
        event->ignore();
    }
}

bool DropListWidget::canDecodeMimeData(const QMimeData* mimeData) const
{
    // 检查数据是否包含文件 URL
    return mimeData && mimeData->hasUrls();
}