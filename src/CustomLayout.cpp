#include "./headers/CustomLayout.h"

CustomLayout::~CustomLayout()
{
     QLayoutItem *item;
     while ((item = takeAt(0)))
         delete item;
}

void CustomLayout::addItem(QLayoutItem *item){
    m_items.append(item);
}
QSize CustomLayout::sizeHint() const{
    QSize s(0, 0);
       int n = m_items.count();
       if (n > 0)
           s = QSize(150, 100);
       int i = 0;
       while (i < n) {
           QLayoutItem *o = m_items.at(i);
           s = s.expandedTo(o->sizeHint());
           ++i;
       }
       return s + n * QSize(spacing(), spacing());
}

QSize CustomLayout::minimumSize() const{
    QSize s(0, 0);
      int n = m_items.count();
      int i = 0;
      while (i < n) {
          QLayoutItem *o = m_items.at(i);
          s = s.expandedTo(o->minimumSize());
          ++i;
      }
      return s + n * QSize(spacing(), spacing());
}

QSize CustomLayout::maximumSize() const{
    QSize s(0, 0);
      int n = m_items.count();
      int i = 0;
      while (i < n) {
          QLayoutItem *o = m_items.at(i);
          s = s.expandedTo(o->maximumSize());
          ++i;
      }
      return s + n * QSize(spacing(), spacing());
}
int CustomLayout::count() const{
    return m_items.length();
}
QLayoutItem *CustomLayout::itemAt(int i) const{
    return m_items.value(i);
}
QLayoutItem *CustomLayout::takeAt(int i){
    return i >= 0 && i < m_items.size() ? m_items.takeAt(i) : 0;
}

void CustomLayout::setGeometry(const QRect &r){
    QLayout::setGeometry(r);

    if (m_items.size() == 0)
        return;

    int w = r.width() - (m_items.count() - 1) * spacing();
    int h = r.height() - (m_items.count() - 1) * spacing();
    int i = 0;
    while (i < m_items.size()) {
        QLayoutItem *o = m_items.at(i);
        QRect geom(r.x() + i * spacing(), r.y() + i * spacing(), w, h);
        o->setGeometry(geom);
        ++i;
    }
}
