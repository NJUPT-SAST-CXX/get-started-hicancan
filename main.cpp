#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <QTimer>

class PhotoAlbum : public QWidget {
public:
    PhotoAlbum(QWidget *parent = nullptr);

private slots:
    void loadImage();

private:
    QLabel *imageLabel;
};

PhotoAlbum::PhotoAlbum(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(imageLabel);

    QPushButton *loadButton = new QPushButton("加载图片", this);
    connect(loadButton, &QPushButton::clicked, this, &PhotoAlbum::loadImage);
    layout->addWidget(loadButton);

    setLayout(layout);
    setWindowTitle("电子相册");
    resize(800, 600);

    // 添加定时器，1分钟后退出程序
    QTimer::singleShot(60000, this, &QWidget::close);
}

void PhotoAlbum::loadImage() {
    QString fileName = QFileDialog::getOpenFileName(this, "选择图片", "", "Images (*.png *.xpm *.jpg)");
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PhotoAlbum album;
    album.show();

    return app.exec();
}
