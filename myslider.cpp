#include "myslider.h"
#include "ui_myslider.h"

MySlider::MySlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySlider)
{
    ui->setupUi(this);

    // 连接信号槽（相互改变）
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->Slider, SLOT(setValue(int)));
    connect(ui->Slider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));

    int Min = 1;
    int Max = 50;
    int SingleStep = 1;

    /**
     * 微调框
     */
    ui->spinBox->setRange(Min,Max);//设置范围
    ui->spinBox->setSingleStep(SingleStep);//步长
    ui->spinBox->setMinimumHeight(30);

    /**
     * 滑动条
     */
    ui->Slider->setRange(Min,Max);//设置范围
    ui->Slider->setMaximumWidth(100);// 设置最大宽度
    ui->Slider->setTickInterval(10);//设置刻度间隔
    ui->Slider->setTickPosition(QSlider::TicksAbove);//设置刻度显示位置
    ui->Slider->setSingleStep(SingleStep);//设置步长，即移动的变化量
    ui->Slider->setValue(1);//设置初始值
}

MySlider::~MySlider()
{
    delete ui;
}
