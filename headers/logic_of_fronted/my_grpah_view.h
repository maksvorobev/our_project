#ifndef MY_GRPAH_VIEW_H
#define MY_GRPAH_VIEW_H
#include <QGraphicsView>
#include "MoveItem.h"
#include <QGraphicsProxyWidget>
#include <QSharedPointer>
#include "../../FrontedObjects/FrontedGenerator.h"
#include "../../FrontedObjects/FrontedOscilloscope.h"
#include "./headers/generator.h"
#include "./headers/oscilloscope.h"
#include <map>
#include "./headers/main_controller.h"
#include "../../FrontedObjects/FrontedHighPassFilter.h"
#include "./headers/block_low_pass_filter.h"
#include "../../FrontedObjects/FrontedLowPassFilter.h"
#include "./headers/block_high_pass_filter.h"
#include "../../FrontedObjects/FrontedCombiner.h"
#include "./headers/Cambiner.h"
#include "../../FrontedObjects/FrontedHarmonyOscilloscope.h"
#include "../../FrontedObjects/FrontedTransformer.h"


class QDropEvent;
class QDragEnterEvent;
class QDragLeaveEvent;


class my_grpah_view: public QGraphicsView{
    Q_OBJECT
public:
    my_grpah_view();
    explicit my_grpah_view(QWidget *parent = nullptr);
    void set_main_controller(Main_Controller* controller);


    void create_oscilloscope();
    void create_generator(Signal *s);
    void create_high_pass_filter();
    void create_low_pass_filter();
    void create_combiner();
    void create_harmony_oscilloscope();
    void create_transformer(double T_coef, double a_coef);
protected:
   // drag&drop
   void dropEvent(QDropEvent *event) override;
   void dragEnterEvent(QDragEnterEvent *event) override;
   void dragLeaveEvent (QDragLeaveEvent *event) override;
   void dragMoveEvent(QDragMoveEvent *event) override;
   std::map<int, Block*> myMap;
   Main_Controller* myController;



private:
   QSharedPointer<QGraphicsScene> scene;
};

#endif // MY_GRPAH_VIEW_H
