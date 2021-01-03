#ifndef ENTITY_MESSAGE_H
#define ENTITY_MESSAGE_H

#include <QMetaType>
#include <QString>

enum MESSAGE_TYPE
{
    MSG_SYSTEM,
    MSG_SENT,
    MSG_RECEIVED
};

enum MESSAGE_ITEM_TYPE
{
    MSG_ITEM_TEXT,
    MSG_ITEM_IMAGE
};

typedef struct _ChatMsg_
{
    int msg_type;
    int msg_item_type;
    QString text;

} ChatMsg;
Q_DECLARE_METATYPE(ChatMsg)

#endif // ENTITY_MESSAGE_H
