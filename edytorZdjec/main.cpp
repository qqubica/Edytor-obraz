#include <iostream>
#include <SFML/Graphics.hpp>
#include "opencv2/opencv.hpp"

inline bool checkForClick(sf::RectangleShape *button, int x, int y);

inline void afterCut(cv::Mat image, cv::Mat editImg, bool *firstEdit);

void topCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image);

void leftCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image);

void rightCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image);

void downCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image);

inline sf::Text creatTxt(std::string txt, sf::RectangleShape button);

inline sf::Text creatTxt2(std::string txt, sf::RectangleShape button);

inline sf::RectangleShape createButton55(sf::RenderWindow *rw);

inline sf::RectangleShape createButton35(sf::RenderWindow *rw);

inline sf::RectangleShape createButton56(sf::RenderWindow *rw);

inline sf::Text inputPrepare(std::string txt);

void saveImage(std::string path, cv::Mat *changed);

void saveAs(std::string path, cv::Mat *editImg);

void saveAsAfterMult(std::string path, cv::Mat *saveThis);

std::string imputWindow(sf::RenderWindow *window, sf::Event e, int version);

cv::Mat *multiply(cv::Mat *mat, cv::Mat *mat2, cv::Mat *resultMat);

int main() {
    sf::Event e;
    std::string path;

    sf::RenderWindow window(sf::VideoMode(1024, 768), "Projekt", sf::Style::Close | sf::Style::Titlebar);

    sf::RectangleShape b1= createButton55(&window);
    b1.setPosition(sf::Vector2f(window.getSize().x / 5 * 2, window.getSize().y / 5));

    sf::RectangleShape b2 = createButton55(&window);
    b2.setPosition(sf::Vector2f(window.getSize().x / 5 * 2, window.getSize().y / 5 * 3));

    sf::Text text1 = creatTxt("Load Image", b1);
    sf::Text text2 = creatTxt("Mix image", b2);

    while (window.isOpen()) {
        window.draw(b1);
        window.draw(b2);
        window.draw(text1);
        window.draw(text2);

        if (window.pollEvent(e)) {
            if (e.type == sf::Event::MouseButtonReleased) {

                int x = e.mouseButton.x;
                int y = e.mouseButton.y;

                if (checkForClick(&b1, x, y)) {

                    path = imputWindow(&window, e, 0);

                    cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);

                    if (image.empty())
                        std::cout << "image error" << std::endl;
                    else {
                        cv::imshow("image", image);
                        cv::waitKey();
                        cv::destroyWindow("image");

                        sf::RectangleShape b3 = createButton35(&window);
                        b3.setPosition(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 5));

                        sf::RectangleShape b4 = createButton35(&window);
                        b4.setPosition(sf::Vector2f(window.getSize().x / 3, window.getSize().y / 5 * 3));

                        sf::Text text3 = creatTxt("Wczytaj inny obraz", b3);

                        sf::Text text4 = creatTxt("Przytnij", b4);

                        window.setVisible(true);

                        while (window.getSize().x == 800) {

                            window.draw(b3);
                            window.draw(text3);
                            window.draw(b4);
                            window.draw(text4);

                            if (window.pollEvent(e)) {
                                if (e.type == sf::Event::MouseButtonReleased) {
                                    x = e.mouseButton.x;
                                    y = e.mouseButton.y;

                                    if (checkForClick(&b3, x, y)) {

                                        window.create(sf::VideoMode(1024, 768),
                                                      "Projekt",sf::Style::Close | sf::Style::Titlebar);
                                    }

                                    if (checkForClick(&b4, x, y)) {

                                        window.create(sf::VideoMode(1000, 750), "Projekt",
                                                       sf::Style::Close | sf::Style::Titlebar);

                                        sf::RectangleShape b5 = createButton56(&window);
                                        b5.setPosition(
                                                sf::Vector2f(window.getSize().x / 5 * 2, window.getSize().y / 6));

                                        sf::RectangleShape b6 = createButton56(&window);
                                        b6.setPosition(
                                                sf::Vector2f(window.getSize().x / 5, window.getSize().y / 6 * 2));

                                        sf::RectangleShape b7 = createButton56(&window);
                                        b7.setPosition(
                                                sf::Vector2f(window.getSize().x / 5 * 3, window.getSize().y / 6 * 2));

                                        sf::RectangleShape b8 = createButton56(&window);
                                        b8.setPosition(
                                                sf::Vector2f(window.getSize().x / 5 * 2, window.getSize().y / 6 * 3));

                                        sf::RectangleShape b9 = createButton56(&window);
                                        b9.setPosition(
                                                sf::Vector2f(window.getSize().x / 5, window.getSize().y / 5 * 4));

                                        sf::RectangleShape b10 = createButton56(&window);
                                        b10.setPosition(
                                                sf::Vector2f(window.getSize().x / 5 * 3, window.getSize().y / 5 * 4));

                                        sf::Text text5 = creatTxt2("Przytnij 100\nz gory", b5);

                                        sf::Text text6 = creatTxt2("Przytnij 100\nz lewej", b6);

                                        sf::Text text7 = creatTxt2("Przytnij 100\nz prawej", b7);

                                        sf::Text text8 = creatTxt2("Przytnij 100\nz dolu", b8);

                                        sf::Text text9 = creatTxt("Save", b9);

                                        sf::Text text10 = creatTxt("Save as", b10);

                                        bool firstEdit = true;
                                        cv::Mat editImg;

                                        while (window.getSize().x == 1000) {

                                            window.draw(b5);
                                            window.draw(b6);
                                            window.draw(b7);
                                            window.draw(b8);
                                            window.draw(b9);
                                            window.draw(b10);

                                            window.draw(text5);
                                            window.draw(text6);
                                            window.draw(text7);
                                            window.draw(text8);
                                            window.draw(text9);
                                            window.draw(text10);

                                            if (window.pollEvent(e)) {
                                                if (e.type == sf::Event::MouseButtonReleased) {
                                                    x = e.mouseButton.x;
                                                    y = e.mouseButton.y;

                                                    if (checkForClick(&b5, x, y)) {

                                                        topCut(&firstEdit, &editImg, &image);
                                                        afterCut(image, editImg, &firstEdit);
                                                    }

                                                    if (checkForClick(&b6, x, y)) {

                                                        leftCut(&firstEdit, &editImg, &image);
                                                        afterCut(image, editImg, &firstEdit);
                                                    }

                                                    if (checkForClick(&b7, x, y)) {

                                                        rightCut(&firstEdit, &editImg, &image);
                                                        afterCut(image, editImg, &firstEdit);
                                                    }

                                                    if (checkForClick(&b8, x, y)) {

                                                        downCut(&firstEdit, &editImg, &image);
                                                        afterCut(image, editImg, &firstEdit);
                                                    }

                                                    if (checkForClick(&b9, x, y)) {

                                                        saveImage(path, &editImg);
                                                        window.create(sf::VideoMode(1024, 768),
                                                                      "Projekt",
                                                                       sf::Style::Close | sf::Style::Titlebar);
                                                    }

                                                    if (checkForClick(&b10, x, y)) {

                                                        std::string saveAsPath = imputWindow(&window, e, 1);
                                                        saveAs(saveAsPath, &editImg);
                                                        window.create(sf::VideoMode(1024, 768),
                                                                      "Projekt",
                                                                       sf::Style::Close | sf::Style::Titlebar);
                                                    }
                                                }
                                            }
                                            if (e.type == sf::Event::Closed) {
                                                window.close();
                                            }
                                            window.display();
                                            window.clear(sf::Color::Black);
                                        }
                                    }
                                }
                                if (e.type == sf::Event::Closed) {
                                    window.close();
                                }
                                window.display();
                                window.clear(sf::Color::Black);
                            }
                        }
                    }
                }
                if (checkForClick(&b2, x, y)) {

                    path = imputWindow(&window, e, 2);
                    std::string path1 = imputWindow(&window, e, 3);

                    window.create(sf::VideoMode(800, 600), "save", sf::Style::Close | sf::Style::Titlebar);

                    sf::RectangleShape button12 = createButton55(&window);
                    button12.setPosition(sf::Vector2f(window.getSize().x / 5 * 2, window.getSize().y / 5 * 2));

                    sf::Text text12 = creatTxt("save as", button12);

                    while (window.getSize().x == 800) {

                        window.draw(button12);
                        window.draw(text12);

                        if (window.pollEvent(e)) {
                            if (e.type == sf::Event::MouseButtonReleased) {
                                x = e.mouseButton.x;
                                y = e.mouseButton.y;
                                if (checkForClick(&button12, x, y)) {

                                    using namespace cv;
                                    Mat m1 = imread(path);
                                    Mat m2 = imread(path1);

                                    window.setVisible(false);
                                    Mat result;

                                    multiply(&m1, &m2, &result);

                                    saveAsAfterMult(imputWindow(&window, e, 1), &result);

                                    window.create(sf::VideoMode(1024, 768), "projekt",
                                                   sf::Style::Close | sf::Style::Titlebar);

                                }
                            }
                        }
                        if (e.type == sf::Event::Closed) {
                            window.close();
                        }
                        window.display();
                        window.clear(sf::Color::Black);
                    }
                }
            }
        }
        if (e.type == sf::Event::Closed) {
            window.close();
        }
        window.display();
        window.clear(sf::Color::Black);
    }
    return 0;
}

cv::Mat *multiply(cv::Mat *mat, cv::Mat *mat2, cv::Mat *resultMat) {
    using namespace cv;

    int cols = mat->cols > mat2->cols ? mat2->cols : mat->cols;
    int rows = mat->rows > mat2->rows ? mat2->rows : mat->rows;

    Mat convertion1;
    Mat convertion2;

    mat->convertTo(convertion1, CV_32F, 1.0 / 255.0);
    mat2->convertTo(convertion2, CV_32F, 1.0 / 255.0);

    *resultMat = Mat(rows, cols, convertion1.type());

    for (int i = 0; i < resultMat->rows; ++i) {
        for (int j = 0; j < resultMat->cols; ++j) {
            for (int k = 0; k < convertion1.channels() + 1; ++k) {
                resultMat->at<Vec3f>(i, j)[k] = convertion1.at<Vec3f>(i, j)[k] * convertion2.at<Vec3f>(i, j)[k];
            }
        }
    }
    if (!resultMat->empty()) {
        imshow("after Mix", *resultMat);
        waitKey(0);
        destroyWindow("after Mix");
    }

    return resultMat;
}

void saveImage(std::string path, cv::Mat *changed) {
    if (!changed->empty())
        cv::imwrite(path, *changed);
}

void saveAsAfterMult(std::string path, cv::Mat *saveThis) {

    saveThis->convertTo(*saveThis, 16, 255.0);

    cv::imwrite(path, *saveThis);
}

void saveAs(std::string path, cv::Mat *editImg) {
    if (!editImg->empty()) {
        cv::imwrite(path, *editImg);
    }
}

sf::Text inputPrepare(std::string txt) {
    static sf::Font font;

    font.loadFromFile("..//arial.ttf");

    sf::Text text(txt, font);

    text.setCharacterSize(12);
    text.setFillColor(sf::Color(235, 223, 223));

    return text;
}

inline bool checkForClick(sf::RectangleShape *button, int x, int y) {
    if (x >= button->getPosition().x &&
        x <= button->getSize().x + button->getPosition().x &&
        y >= button->getPosition().y &&
        y <= button->getPosition().y + button->getSize().y)
        return true;

    return false;
}

inline sf::Text creatTxt(std::string txt, sf::RectangleShape button) {
    static sf::Font font;

    if (!font.loadFromFile("..//arial.ttf"))
        std::cout << "Font loading error" << std::endl;

    sf::Text text(txt, font);

    text.setFillColor(sf::Color(235, 223, 223));
    text.setPosition(
            sf::Vector2f(
                    (button.getPosition().x + button.getSize().x / 2) - text.getLocalBounds().width / 2,
                    button.getPosition().y + button.getSize().y / 3
            ));

    return text;
}

inline sf::Text creatTxt2(std::string txt, sf::RectangleShape button) {
    static sf::Font font;

    if (!font.loadFromFile("..//arial.ttf"))
        std::cout << "Font loading error" << std::endl;

    sf::Text text(txt, font);

    text.setFillColor(sf::Color(235, 223, 223));
    text.setPosition(sf::Vector2f((button.getPosition().x + button.getSize().x / 2) - text.getLocalBounds().width / 2,
                                  button.getPosition().y + button.getSize().y / 5));
    return text;
}

inline sf::RectangleShape createButton55(sf::RenderWindow *rw) {
    sf::RectangleShape rectangleShape(sf::Vector2f(rw->getSize().x / 5, rw->getSize().y / 5));

    rectangleShape.setFillColor(sf::Color(91, 83, 181));

    return rectangleShape;
}

inline sf::RectangleShape createButton35(sf::RenderWindow *rw) {
    sf::RectangleShape rectangleShape(sf::Vector2f(rw->getSize().x / 3, rw->getSize().y / 5));

    rectangleShape.setFillColor(sf::Color(91, 83, 181));

    return rectangleShape;
}

inline sf::RectangleShape createButton56(sf::RenderWindow *rw) {
    sf::RectangleShape rectangleShape(sf::Vector2f(rw->getSize().x / 5, rw->getSize().y / 6));

    rectangleShape.setFillColor(sf::Color(91, 83, 181));

    return rectangleShape;
}

void downCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image) {
    if (*firstEdit) {
        *editImg = cv::Mat(image->rows - 100, image->cols, image->type());
        for (int i = 0; i < editImg->rows; ++i) {
            for (int j = 0; j < editImg->cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = image->at<cv::Vec3b>(i, j);
            }
        }
    } else {
        cv::Mat tmp(editImg->rows - 100, editImg->cols, editImg->type());
        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                tmp.at<cv::Vec3b>(i, j) = editImg->at<cv::Vec3b>(i, j);
            }
        }
        *editImg = cv::Mat(tmp.rows, tmp.cols, tmp.type());
        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = tmp.at<cv::Vec3b>(i, j);
            }
        }
    }
}

void leftCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image) {
    if (*firstEdit) {
        *editImg = cv::Mat(image->rows, image->cols - 100, image->type());

        for (int i = 0; i < editImg->rows; ++i) {
            for (int j = 0; j < editImg->cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = image->at<cv::Vec3b>(i, j + 100);
            }
        }

    } else {
        cv::Mat tmp(editImg->rows, editImg->cols - 100, editImg->type());

        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                tmp.at<cv::Vec3b>(i, j) = editImg->at<cv::Vec3b>(i, j + 100);
            }
        }

        *editImg = cv::Mat(tmp.rows, tmp.cols, tmp.type());

        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = tmp.at<cv::Vec3b>(i, j);
            }
        }

    }
}

void rightCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image) {
    if (*firstEdit) {
        *editImg = cv::Mat(image->rows, image->cols - 100, image->type());

        for (int i = 0; i < editImg->rows; ++i) {
            for (int j = 0; j < editImg->cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = image->at<cv::Vec3b>(i, j);
            }
        }
    } else {
        cv::Mat tmp(editImg->rows, editImg->cols - 100, editImg->type());

        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                tmp.at<cv::Vec3b>(i, j) = editImg->at<cv::Vec3b>(i, j);
            }
        }

        *editImg = cv::Mat(tmp.rows, tmp.cols, tmp.type());

        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = tmp.at<cv::Vec3b>(i, j);
            }
        }
    }
}

void topCut(bool *firstEdit, cv::Mat *editImg, cv::Mat *image) {
    using namespace cv;
    if (*firstEdit) {
        *editImg = Mat(image->rows - 100, image->cols, image->type());

        for (int i = 0; i < editImg->rows; ++i) {
            for (int j = 0; j < editImg->cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = image->at<cv::Vec3b>(i + 100, j);
            }
        }
    } else {
        Mat tmp(editImg->rows - 100, editImg->cols, editImg->type());

        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                tmp.at<cv::Vec3b>(i, j) = editImg->at<cv::Vec3b>(i + 100, j);
            }
        }

        *editImg = Mat(tmp.rows, tmp.cols, tmp.type());

        for (int i = 0; i < tmp.rows; ++i) {
            for (int j = 0; j < tmp.cols; ++j) {
                editImg->at<cv::Vec3b>(i, j) = tmp.at<cv::Vec3b>(i, j);
            }
        }
    }
}

inline void afterCut(cv::Mat image, cv::Mat editImg, bool *firstEdit) {
    cv::imshow("Orginal image", image);
    cv::imshow("After cut", editImg);
    cv::waitKey(0);
    cv::destroyAllWindows();

    *firstEdit = false;
}

std::string imputWindow(sf::RenderWindow *window, sf::Event e, int version) {
    std::string path;
    std::string txt;

    window->create(sf::VideoMode(300, 150), "Wprowadz sciezke", sf::Style::Titlebar);

    switch (version) {
        case 0:
            txt = "Wprowadz sciezke do pliku ktory chcesz wczytac\n(aby zakonczyc wprowadzanie nacisnij enter):";
            break;
        case 1:
            txt = "Wprowadz sciezke do zapisania pliku\n(aby zakonczyc wprowadzanie nacisnij enter):";
            break;
        case 2:
            txt = "Wprowadz sciezek 1 obrazu do mixu\n(aby zakonczyc wprowadzanie nacisnij enter):";
            break;
        case 3:
            txt = "Wprowadz sciezek 2 obrazu do mixu\n(aby zakonczyc wprowadzanie nacisnij enter):";
            break;
    }

    sf::Text pathInfo = inputPrepare(txt);
    sf::Text pathPath = inputPrepare(path);

    pathPath.setPosition(sf::Vector2f(0, pathInfo.getLocalBounds().height + 3));

    while (window->getSize().x == 300) {

        window->draw(pathInfo);
        window->draw(pathPath);

        if (window->pollEvent(e)) {
            if (e.type == sf::Event::TextEntered && e.text.unicode >= 33 && e.text.unicode <= 126) {
                path += (char) e.text.unicode;
                pathPath.setString(path);
            } else if (e.type == sf::Event::TextEntered && e.text.unicode == 8) {
                path = path.substr(0, path.length() - 1);
                pathPath.setString(path);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                if (path.length() == 0) {
                    path = "..\\1.jpg";
                    std::cout << "no path imput" << std::endl;
                } else
                    std::cout << "your path: " << path << std::endl;

                window->create(sf::VideoMode(800, 600), "input", sf::Style::Close | sf::Style::Titlebar);

                if (version <= 1)
                    window->setVisible(false);
            }
        }
        if (e.type == sf::Event::Closed) {
            window->close();
        }
        window->display();
        window->clear(sf::Color::Black);
    }
    return path;
}