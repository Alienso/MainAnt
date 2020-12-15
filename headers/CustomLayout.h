#ifndef CUSTOMLAYOUT_H
#define CUSTOMLAYOUT_H

#include <QLayout>
#include <QVector>

class CustomLayout : public QLayout{

private:
    QVector<QLayoutItem*> m_items;

public:

    CustomLayout(int spacing): QLayout()
    { setSpacing(spacing); }
    CustomLayout(int spacing, QWidget *parent): QLayout(parent)
    { setSpacing(spacing); }
    ~CustomLayout();

    void addItem(QLayoutItem *item) override;
    QSize sizeHint() const override;
    QSize minimumSize() const override;
    QSize maximumSize() const override;
    int count() const override;
    QLayoutItem *itemAt(int) const override;
    QLayoutItem *takeAt(int) override;
    void setGeometry(const QRect &rect) override;

};
#endif // CUSTOMLAYOUT_H
