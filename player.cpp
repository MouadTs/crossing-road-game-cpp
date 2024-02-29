#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QApplication>
#include <QList>
#include <QMessageBox>
#include "vehicule.h"
#include "game.h"
#include "retrydialog.h"

extern Game *game;

player::player() {
    QPixmap originalpixmap(":/F:/ressources/Untitled_design-removebg-preview.png");
    int phight = 140;
    int pwidth = 120;

    QPixmap scaledpix = originalpixmap.scaled(phight, pwidth);

    setPixmap(scaledpix);

    distanceCounter=0;
}

void player::keyPressEvent(QKeyEvent *event) {
    // if player collides with a car ??
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Car)) {
            // Ask the user if they want to try again or quit
            RetryDialog retryDialog;
            int result = retryDialog.exec();
            if (result == RetryDialog::Quit) {
                // User chose to quit
                QApplication::quit();
            } else if (result == RetryDialog::Retry) {
                // User chose to try again
                game->getscore()->reset(); // Reset the score
                distanceCounter=0;
                setPos(game->getview()->width() / 2, game->getview()->height() - pixmap().height() - 20);
                game->getview()->setSceneRect(0, 0, 800, 600);  // Optionally reset the scene rect
                setFocus();  // Set focus back on the player
            }
            // Remove the car
            scene()->removeItem(colliding_items[i]);
        }
    }

    // Handle movement keys
    if (event->key() == Qt::Key_Left) {
        moveLeft();
    } else if (event->key() == Qt::Key_Right) {
        moveRight();
    } else if (event->key() == Qt::Key_Up) {
        moveUp();
    } else if (event->key() == Qt::Key_Down) {
        moveDown();
    }
}

void player::keyReleaseEvent(QKeyEvent *event) {
    // Reset the player's image when no keys are pressed
    setPlayerImage(":/F:/ressources/Untitled_design-removebg-preview.png");

}

void player::moveLeft() {
    // Move the player left
    if (pos().x() > 0) {
        setPos(x() - 10, y());
        setPlayerImage(":/F:/ressources/walk.png");
        setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);  // Set origin to the center
        setRotation(-90);  // Reset rotation to zero
    }
}

void player::moveRight() {
    // Move the player right
    if (pos().x() + 50 < 800) {
        setPos(x() + 10, y());
        setPlayerImage(":/F:/ressources/walk.png");
        setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);  // Set origin to the center
        setRotation(90);  // Rotate 90        degrees (facing right)
    }
}

void player::moveUp() {
    // Move the player up
    setPos(x(), y() - 10);
    setPlayerImage(":/F:/ressources/walk.png");
    setRotation(0);  // Reset rotation to zero

    // Check if the player reaches the upper limit of the scene
    if (y() < 1800) {
        // Move the scene down to follow the player
        game->getview()->setSceneRect(
            game->getview()->sceneRect().x(),
            game->getview()->sceneRect().y() - 9,
            game->getview()->sceneRect().width(),
            game->getview()->sceneRect().height());

        // Increase the score
        game->getscore()->increase();

        // Update distance counter
        distanceCounter += 10;  // Adjust as needed

        // Check if the player has reached the distance limit
        if (distanceCounter >= 3000) {
            endGame();
        }
    }
}


void player::moveDown() {
    // Move the player down
    if (y() + 10 + pixmap().height() <= scene()->sceneRect().bottom()) {
        setPos(x(), y() + 10);
        setPlayerImage(":/F:/ressources/walk.png");
        setRotation(180);  // Reset rotation to zero

        // Move the scene up to follow the player
        game->getview()->setSceneRect(
            game->getview()->sceneRect().x(),
            game->getview()->sceneRect().y() + 12,
            game->getview()->sceneRect().width(),
            game->getview()->sceneRect().height());
    }
}

void player::setPlayerImage(const QString& imagePath) {
    QPixmap originalpixmap(imagePath);
    int phight = 140;
    int pwidth = 120;

    QPixmap scaledpix = originalpixmap.scaled(phight, pwidth);

    setPixmap(scaledpix);
}

void player::endGame() {
    // Add any end-game logic here
    // For example, you can display a game-over message or show a score screen
    // You might also want to stop any ongoing timers or background processes

    // Display a message box
    QMessageBox gameOverBox;
    gameOverBox.setText("Congratulations! You've completed the game!");
    gameOverBox.exec();

    // Quit the application
    QApplication::quit();
}
