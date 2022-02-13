#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <string>
#include<QMessageBox>
#include"lldetem.h"
#include"pessoafisica.h"
#include"pessoajuridica.h"
#include "produto.h"
#include "pedido.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCliente_clicked();

    void on_pushButton_2Produto_clicked();

    void on_pushButton_3Pedido_clicked();

    void on_checkBox_6Cadastrar_clicked();

    void on_checkBox_5Consultar_clicked();

    void on_checkBox_4Remover_clicked();

    void on_checkBox_7Listar_clicked();

    void on_pushButtonCadastrarCliente_clicked();

    void on_pushButton_3Consultar_clicked();

    void on_pushButton_2Remover_clicked();

    void on_pushButtonListar_clicked();

    void on_checkBoxCadastrarProduto_clicked();

    void on_checkBox_2ConsultarProduto_clicked();

    void on_checkBox_3RemoverProduto_clicked();

    void on_checkBox_4ListarProduto_clicked();

    void on_checkBoxCadastrarPedido_clicked();

    void on_checkBox_2ConsultarPedido_clicked();

    void on_checkBox_3RemoverPedido_clicked();

    void on_checkBox_4ListarPedido_clicked();

    void on_pushButtonCadastrarProduto_clicked();

    void on_pushButton_3ListarProduto_clicked();

    void on_pushButton_2ConsultarProduto_clicked();

    void on_pushButtonRemoverProduto_clicked();

    void on_pushButton_2CadastrarPedido_clicked();

    void on_pushButton_3ListarPedido_clicked();

    void on_pushButtonConsultarPedido_clicked();

    void on_pushButton_2RemoverPedido_clicked();

private:
    Ui::MainWindow *ui;

    LTEM<Cliente*> lista;// LISTA DE CLIENTES
    Cliente* cliente; //OBJETO CLIENTE
    std::fstream arquivo; //ARQUIVO DE CLIENTES


    LTEM<Produto*> listaP; //LISTA DE PRODUTOS
    Produto* produto; //OBJETO PRODUTO
    std::fstream arquivoP; //ARQUIVO DE PRODUTOS



    LTEM<Pedido*> listaI; //LISTA DE PEDIDOS
    Pedido* pedido; //OBJETO PEDIDO
    std::fstream arquivoI; //ARQUIVO DE PEDIDOS
};
#endif // MAINWINDOW_H
