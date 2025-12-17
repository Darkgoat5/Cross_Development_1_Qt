#include "movietracker.h"
#include "ui_movietracker.h"
#include "QtWidgets"
#include "moviewidget.h"


MovieTracker::MovieTracker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MovieTracker)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MovieTracker::~MovieTracker()
{
    delete ui;
}

void MovieTracker::on_pushButton_clicked()
{
    QDialog d(this);
    d.setWindowTitle("Add Movie");
    d.setMinimumWidth(300);

    QVBoxLayout *outerLayout = new QVBoxLayout(&d);

    QLabel *titleLabel = new QLabel("Title: ", &d);
    QLabel *genreLabel = new QLabel("Genre: ", &d);
    QLabel *dateLabel = new QLabel("Date: ", &d);


    QLineEdit *titleEdit = new QLineEdit(&d);
    QLineEdit *genreEdit = new QLineEdit(&d);
    QDateEdit *dateEdit = new QDateEdit(&d);
    dateEdit->setCalendarPopup(true);
    dateEdit->setDate(QDate::currentDate());

    outerLayout->addWidget(titleLabel);
    outerLayout->addWidget(titleEdit);
    outerLayout->addWidget(genreLabel);
    outerLayout->addWidget(genreEdit);
    outerLayout->addWidget(dateLabel);
    outerLayout->addWidget(dateEdit);

    QHBoxLayout *RLay = new QHBoxLayout;
    outerLayout->addLayout(RLay);

    RLay->addWidget(new QLabel("Rating: ", &d));

    StarWidget *stars = new StarWidget(&d);

    QVector<QRadioButton*> radios;
    for (int i=0; i<=5; i++) {
        QLabel *lab = new QLabel(QString::number(i), &d);
        QRadioButton *rb = new QRadioButton(&d);
        RLay->addWidget(lab);
        RLay->addWidget(rb);
        radios.append(rb);
    }

    outerLayout->addWidget(stars);
    stars->setStarColor(m_color);

    QPushButton *p = new QPushButton("Add movie", &d);
    p->setEnabled(false);
    outerLayout->addWidget(p);

    connect(p, &QPushButton::clicked, &d, &QDialog::accept);

    auto validate = [=]() {
        bool hasTitle = !titleEdit->text().isEmpty();
        bool hasGenre = !genreEdit->text().isEmpty();
        QDate selectedDate = dateEdit->date();
        bool hasDate = selectedDate.isValid() && selectedDate <= QDate::currentDate();
        bool hasRating = std::any_of(radios.begin(), radios.end(), [](QRadioButton* rb){ return rb->isChecked(); });
        p->setEnabled(hasTitle && hasGenre && hasDate && hasRating);
    };



    connect(titleEdit, &QLineEdit::textChanged, validate);
    connect(genreEdit, &QLineEdit::textChanged, validate);
    connect(dateEdit, &QDateEdit::dateChanged, validate);
    for (int i = 0; i < radios.size(); ++i) {
        connect(radios[i], &QRadioButton::toggled, validate);
        connect(radios[i], &QRadioButton::toggled, this, [=](bool checked)
                                                   {
            if(checked)
            {
                stars->setScore(i);
            }
        });
    }

    if (d.exec() == QDialog::Accepted) {
        QString title = titleEdit->text();
        QString genre = genreEdit->text();
        QDate date = dateEdit->date();

        int score = -1;
        for (int i=0; i<radios.size(); ++i) {
            if (radios[i]->isChecked())
            {
                score = i; break;
            }
        }

        m_movies.append(Movie(title, genre, date, score));

    }

    printMovies();

}

void MovieTracker::printMovies()
{
    ui->listWidget->clear();

    for (int i = 0; i < m_movies.size(); ++i) {
        Movie &m = m_movies[i];
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(QSize(200, 40));
        MovieWidget *widget = new MovieWidget(m, m_color);
        ui->listWidget->setItemWidget(item, widget);
    }
}


void MovieTracker::on_pushButton_2_clicked()
{
    int row = ui->listWidget->currentRow();
    if (row >= 0 && row < m_movies.size()) {
        m_movies.removeAt(row);
        printMovies();
    }
}

void MovieTracker::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open movie rating list", QString(), "Text Files (*.txt);;All Files (*)");

    if (filePath.isEmpty())
        return;

    QFile f(filePath);

    if (!f.open(QIODevice::ReadOnly))
        return;

    QTextStream in(&f);

    m_movies.clear();

    while (!in.atEnd()) {
        QString name = in.readLine();
        QString genre = in.readLine();
        QString dateStr = in.readLine();
        QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
        int score = in.readLine().toInt();

        Movie m(name, genre, date, score);

        m_movies.append(m);

    }
    printMovies();
    f.close();
}


void MovieTracker::on_actionSave_triggered()
{
    if(m_movies.size() <= 0)
        return;

    QString filePath = QFileDialog::getSaveFileName(this, "Save movie rating list", QString(), "Text Files (*.txt);;All Files (*)");

    if (filePath.isEmpty())
        return;

    QFile f(filePath);

    if (!f.open(QIODevice::WriteOnly))
        return;

    QTextStream out(&f);

    for(int i=0; i<m_movies.count(); ++i)
    {
        out << m_movies[i].name() << "\n" << m_movies[i].genre() << "\n" << m_movies[i].release().toString("dd/MM/yyyy") << "\n" << m_movies[i].score() << "\n";
    }

    f.close();
}


void MovieTracker::on_pushButton_3_clicked()
{
    QStackedWidget *sw = ui->stackedWidget;

    if(sw->currentIndex() == 1)
    {
        sw->setCurrentIndex(0);
    }
    else
    {
        sw->setCurrentIndex(1);
    }
}


void MovieTracker::on_comboBox_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        m_color = Qt::yellow;
        break;
    case 1:
        m_color = Qt::red;
        break;
    case 2:
        m_color = Qt::green;
        break;
    case 3:
        m_color = Qt::blue;
        break;
    }
    printMovies();
}

