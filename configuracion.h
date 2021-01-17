/*La empresa LISOFT requiere una GUI que permita configurar su dispositivo denominado  ccs-hub.
El dispositivo necesita almacenar una dirección IP a la cual se conecta el equipo,
se requiere establecer el número de puerto y se necesita establecer las cajas que están habilitadas
(total de 4 cajas) para el funcionamiento del dispositivo 
Todas las configuraciones deben ser persistentes(guardar en archivo)
*/

/*Práctica 09 
 1.Abrir y cargar la información de un archivo de configuración.
 2.Colocar todo en funciones (abrir,guardar)
 3.Mostrar cuadro de diálogo cuando se ha guardado exitosamente un archivo
 4.Mejorar la GUI (icono,colores,tipo de letra) 
 */
#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Configuracion; }
QT_END_NAMESPACE

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    Configuracion(QWidget *parent = nullptr);
    ~Configuracion();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::Configuracion *ui;

};
#endif // CONFIGURACION_H
