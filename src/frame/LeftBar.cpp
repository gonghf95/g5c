#include "LeftBar.h"
#include "ui_LeftBar.h"
#include "src/frame/MainWindow.h"

#include <QAction>

LeftBar::LeftBar(MainWindow *parent)
    : QWidget(parent),
      ui(new Ui::LeftBar),
      moreMenu_(new QMenu(this))
{
    ui->setupUi(this);

    initUI();
    initConnect();
}

LeftBar::~LeftBar()
{
    delete ui;
    delete moreMenu_;
}

void LeftBar::bind(LeftBar::ActivePanel ap, const QVariant &data)
{
    data_[ap] = data;
}

void LeftBar::slotItemClicked()
{
    QPushButton *active_button = qobject_cast<QPushButton*>(sender());
    if(active_button == ui->btn_chat)
    {
        updateActivePanelState(AP_CHAT);
    }
    else if(active_button == ui->btn_contact)
    {
        updateActivePanelState(AP_CONTACT);
    }
    else if(active_button == ui->btn_favourite)
    {
        updateActivePanelState(AP_FAVOURITE);
    }
    else if(active_button == ui->btn_more)
    {
        QPoint pos = mapToGlobal(ui->btn_more->pos());
        moreMenu_->exec(QPoint(pos.x()+50, pos.y()-80));
    }
}

void LeftBar::initUI()
{
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(37, 40, 42));

    setPalette(palette);
    setAutoFillBackground(true);
    setGeometry(0, 0, LEFTBAR_DEFAULT_WIDTH, LEFTBAR_DEFAULT_HEIGHT);

    ui->btn_chat->setToolTip("Chats");
    ui->btn_contact->setToolTip("Contacts");
    ui->btn_favourite->setToolTip("Favourites");
    ui->btn_files->setToolTip("Files");
    ui->btn_topStories->setToolTip("Top Stories");
    ui->btn_miniProgram->setToolTip("Mini Program Panel");
    ui->btn_phone->setToolTip("Phone");
    ui->btn_more->setToolTip("More");

    ui->actionFeedback->setText("Feedback");
    ui->actionBackupAndRestore->setText("Backup and Restore");
    ui->actionSettings->setText("Settings");

    moreMenu_->addAction(ui->actionFeedback);
    moreMenu_->addAction(ui->actionBackupAndRestore);
    moreMenu_->addAction(ui->actionSettings);
    moreMenu_->setCursor(Qt::PointingHandCursor);
    moreMenu_->setToolTipsVisible(true);
    moreMenu_->setStyleSheet("QMenu{background-color: rgb(37, 40, 42);} QMenu::item{height:12px;color:#8A8A8A; padding:12px;}");
}

void LeftBar::initConnect()
{
    connect(ui->btn_chat, SIGNAL(clicked()), SLOT(slotItemClicked()));
    connect(ui->btn_contact, SIGNAL(clicked()), SLOT(slotItemClicked()));
    connect(ui->btn_favourite, SIGNAL(clicked()), SLOT(slotItemClicked()));
    connect(ui->btn_more, SIGNAL(clicked()), SLOT(slotItemClicked()));
}

void LeftBar::updateActivePanelState(LeftBar::ActivePanel new_active_panel)
{
    if(new_active_panel == activePanel_)
        return;

    QString file_path_chat = ":/resource/image/chat_normal.png";
    QString file_path_contact = ":/resource/image/contact_normal.png";
    QString file_path_favourite = ":/resource/image/favourite_normal.png";

    if(AP_CHAT == new_active_panel)
    {
        file_path_chat = ":/resource/image/chat_pressed.png";
    }
    else if(AP_CONTACT == new_active_panel)
    {
        file_path_contact = ":/resource/image/contact_pressed.png";
    }
    else if(AP_FAVOURITE == new_active_panel)
    {
        file_path_favourite = ":/resource/image/favourite_pressed.png";
    }

    ui->btn_chat->setIcon(QIcon(file_path_chat));
    ui->btn_contact->setIcon(QIcon(file_path_contact));
    ui->btn_favourite->setIcon(QIcon(file_path_favourite));

    activePanel_ = new_active_panel;
    emit sigActivePanelChanged(activePanel_, data_[activePanel_]);
}
