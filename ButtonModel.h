//
// Created by maluc on 06/10/2021.
//
/***
 * classe é um modelo de botao para que os botões irao herdar
 * ele permite definir o tamanho do botao e o texto do botao
 * e a posição do botao
 */
#ifndef TRABALHO_BUTTONMODEL_H
#define TRABALHO_BUTTONMODEL_H

#include "SFML/Graphics.hpp"
#include "Clickable.h"

/**
 * @brief Essa classe representa um modelo genérico de um botão.
 *
 */
class ButtonModel : public Clickable {
private:
    sf::RectangleShape button; ///<Corpo do botão
    sf::Text txt;///<Texto escrito no meio do botao.
    sf::Font font;// a fonte tem é um atributo para que ela nao seja perdida após definida, o mesmo para o texto
    //reajuste do texto caso o botao tenha sido modificado
    bool clicked;

    /**
     * Coloca o texto no meio do botao
     * @param pos: posicao do botao
     */
    void setTxtPosition(sf::Vector2f pos);

    /**
     * Inicia posição e tamanho do botão
     * @param pos posição na window.
     * @param tam tamanho do botão.
     */
    void initButton(sf::Vector2f pos, sf::Vector2f tam);

    /**
     * Inicia as definições padrões do texto do botão.
     */
    void initText();

    /**
     * Carrega a fonte do texto.
     */
    void initFont();

    /**
     * Inicia as variáveis da classe.
     */
    void initVariables();
public:
    /**
     * construtor do botao modelo
     * @param pos :posicao do botao
     * @param tam :tamanho do botao
     */
    explicit ButtonModel(sf::Vector2f pos, sf::Vector2f tam = sf::Vector2f(100.f, 50.f));

    ButtonModel();

    ~ButtonModel() override;

    /**
     * Define o tamanho do botão
     * @param tam :tamanho do botão
     */
    void setSize(sf::Vector2f tam);
    /**
     * Define o tamanho do botão
     * @param tamX tamanho em X
     * @param tamY tamanho em Y
     */
    void setSize(float tamX, float tamY);

    /**
     * define posicao do botao
     * @param pos :posicao
     */
    void setPosition(sf::Vector2f pos);
    void setPosition(float posX, float posY);

    /**
     * define texto do botao
     * @param texto
     */
    void setText(std::string texto);

    /**
     * define cor do texto do botao
     * @param color :a cor passada como paramemtro é referente a biblioteca sf::Color
     */
    void setTextColor(sf::Color color);

    /**
     *  define cor de fundo do botao
     * @param color :cor do botao
     */
    void setButtonColor(sf::Color color);

    /**
     * define cor da borda do botao
     * @param color
     */
    void setOutLineColor(sf::Color color);

    /**
     * define grossura da borda do botao
     * @param thickness
     */
    void setOutlineThickness(float thickness);

    /**
     * desenha o botao
     * @param window :janela aonde o botao sera impresso
     */
    void drawButton(sf::RenderTarget &target);

    /**
     * verifica se o mouse esta dentro do botao
     * @param posicao:posicao do mouise
     * @return
     */
    bool contains(sf::Vector2f posicao) override;

    /**
     * Verifica se o botão é clicado utilizando um evento.
     * Caso o Evento seja Event::MouseButtonReleased, quer dizer que o botão já pode receber outro click.
     * @param event Evento
     */
    void canClick(sf::Event &event);
    /**
     * carregaa uma fonte nova para o texto
     * @param path :caminho da fonte
     */
    void setFont(sf::String path);

};


#endif //TRABALHO_BUTTONMODEL_H
