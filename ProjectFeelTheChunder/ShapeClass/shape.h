#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPaintDevice>
#include <QPoint>
#include <QString>
#include <QPainter>
// : public QPainter


class Shape : public QPainter
{
	public:
		Shape();


        void setShape(ShapeType);
        void setBrush(Qt::GlobalColor, Qt::BrushStyle);
        void setPen(Qt::GlobalColor);
        void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);

        ShapeType getShape() const;
        const QBrush &getBrush() const;
        const QPen &getPen() const;

        void setDefaultStyle();

        virtual void move(const int tX, const int tY) = 0;
        virtual void draw() = 0;
        virtual double perimeter() = 0;
        virtual double area() = 0;
    protected:
        QPainter &get_qpainter();
    private:
        QPainter painter;
        int id;
        ShapeType shape;
        QPen pen;
        QBrush brush;
};

#endif // SHAPE_H
