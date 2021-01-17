/*Práctica 09 
 1.Abrir y cargar la información de un archivo de configuración.
 2.Colocar todo en funciones (abrir,guardar)
 3.Mostrar cuadro de diálogo cuando se ha guardado exitosamente un archivo
 4.Mejorar la GUI (icono,colores,tipo de letra) 
 */
#include "configuracion.h"
#include "ui_configuracion.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include "dialog.h"

Configuracion::Configuracion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Configuracion)
{
    ui->setupUi(this);
}

Configuracion::~Configuracion()
{
    delete ui;
}


void Configuracion::on_pushButton_clicked()
{
    //Obtener la informacion de la GUI

    QString direccion = ui->inDireccion->text();
    int puerto= ui->inPuerto->value();
    bool caja1 = ui->chkCaja1->isChecked();
    bool caja2 = ui->chkCaja2->isChecked();
    bool caja3 = ui->chkCaja3->isChecked();
    bool caja4 = ui->chkCaja4->isChecked();


    //Verificar si la información recopilada es correcta
    //qDebug()<< direccion<<puerto<<caja1<<caja2<<caja3<<caja4;

    //Establece un nombre de archivo temporal en el directorio "home" del usuario
    QString temporal = QDir::home().absolutePath() +"sin_titulo.cfg";
    qDebug() << temporal;

    QString  nombreArchivo = QFileDialog::getSaveFileName(this, "Guardar configuracion",
                                                     temporal,
                                                  "Archivo de configuracion (*.cfg)"); //Filtro en el que guarda mi extension de dialogo

    //Crear el objeto QFile
    QFile archivo(nombreArchivo);

    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
          //Crear el objeto QTextStream
          QTextStream out(&archivo);
          //Escribiendo datos en el archivo
          out<< "Servidor="<< direccion<<'\n';
          out<< "Puerto="<<puerto<<'\n';
          out<< "Caja 1="<<caja1 <<'\n';
          out<< "Caja 2="<<caja2 <<'\n';
          out<< "Caja 3="<<caja3 <<'\n';
          out<< "Caja 4="<<caja4 <<'\n';


          //Cerrar el archivo
          archivo.close();
          //qDebug() << "Archivo almacenado en:" << archivo;

          Dialog dialogo;
          //dialogo.setModal(true);
          dialogo.exec();


    }
}

void Configuracion::on_pushButton_2_clicked()
{


    QString temporal = QDir::home().absolutePath() +"sin_titulo.cfg";

    QString  nombreArchivo = QFileDialog::getOpenFileName(this, "Guardar configuracion",
                                                     temporal,
                                                  "Archivo de configuracion (*.cfg)"); //Filtro en el que guarda mi extension de dialogo

    //Crear el objeto QFile
    QFile archivo(nombreArchivo);

    if (archivo.open(QIODevice::ReadOnly))
    {
       QTextStream in(&archivo);


       while (!in.atEnd())
       {

        QString line = in.readLine();
        QStringList valores = line.split("=");

        if(valores[0] == "Servidor"){
           ui->inDireccion->setText(valores[1]);
        }else{
            if(valores[0] == "Puerto"){
                ui->inPuerto->setValue(valores[1].toInt());
            }else{
                if(valores[0] == "Caja 1"){
                    if(valores[1] == "1"){
                        ui->chkCaja1->setChecked(true);
                    }else{
                        ui->chkCaja1->setChecked(false);
                    }
                }else{
                    if(valores[0] == "Caja 2"){
                        if(valores[1] == "1"){
                            ui->chkCaja2->setChecked(true);
                        }else{
                            ui->chkCaja2->setChecked(false);
                        }
                    }else{
                        if(valores[0] == "Caja 3"){
                            if(valores[1] == "1"){
                                ui->chkCaja3->setChecked(true);
                            }else{
                                ui->chkCaja3->setChecked(false);
                            }
                        }else{
                            if(valores[0] == "Caja 4"){
                                if(valores[1] == "1"){
                                    ui->chkCaja4->setChecked(true);
                                }else{
                                    ui->chkCaja4->setChecked(false);
                                }
                            }
                        }
                    }
                }
            }
        }
       }
       archivo.close();
    }

}
