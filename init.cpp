#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>

void runBatchScript()
{
    system("kernel.bat");
}

void runShellScript()
{
    system("kernel.sh");
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 创建主窗口
    QWidget window;
    window.setWindowTitle("多玩我的世界联机盒子 | MinecraftOnlineTools");

    // 创建标题标签
    QLabel titleLabel(&window);
    titleLabel.setText("多玩我的世界联机盒子 | MinecraftOnlineTools");
    titleLabel.setGeometry(50, 50, 300, 30);

    // 创建按钮
    QPushButton startButton(&window);
    startButton.setText("Start");
    startButton.setGeometry(50, 100, 100, 30);
    QObject::connect(&startButton, &QPushButton::clicked, &runBatchScript); // 点击按钮运行kernel.bat
    QObject::connect(&startButton, &QPushButton::clicked, &runShellScript); // 点击按钮运行kernel.sh

    // 创建第一个标签
    QLabel mcCommunityLabel(&window);
    mcCommunityLabel.setText("<a href=\"https://bbs.mc-m.net/\">m社——minecraft社区</a>");
    mcCommunityLabel.setGeometry(50, 150, 300, 30);
    mcCommunityLabel.setOpenExternalLinks(true); // 在浏览器中打开链接

    // 创建第二个标签
    QLabel officialWebsiteLabel(&window);
    officialWebsiteLabel.setText("<a href=\"https://mc-m.net/\">官网</a>");
    officialWebsiteLabel.setGeometry(50, 200, 100, 30);
    officialWebsiteLabel.setOpenExternalLinks(true); // 在浏览器中打开链接

    window.resize(400, 300);
    window.show();

    return app.exec();
}
