#ifndef NOTECLIENT_H
#define NOTECLIENT_H

#include <QtWidgets/QMainWindow>
#include "ui_noteclient.h"

class NoteClient : public QMainWindow
{
	Q_OBJECT

public:
	NoteClient(QWidget *parent = 0);
	~NoteClient();
	//void NoteClient::resizeEvent(QResizeEvent *);
	QString getCurrentDateTime(); 
	QString getCurrentYearMonth();
	QString parseFileName2Title(const QString &fileName);
	QString parseFileName2YMBase(const QString &fileName);

	Ui::NoteClientClass getUiClass() { return ui; }
protected:
	void NoteClient::closeEvent(QCloseEvent *event);

	private slots:

	bool on_geneButton_clicked();
	void on_selectFileButton_clicked();
	void on_clearButton_clicked();
	void setCodeButtonText(bool toggled);
	void noteModified();
	void setFont(int fontsize);

private:
	Ui::NoteClientClass ui;
	QLabel *statusLabel;

	QString curFile;

	void createStatusBar();
	bool geneFile(const QString &fileName);
	bool writeFile(const QString &fileName);
	bool readFile(const QString &fileName);
	void triggerStatus(const QString &status);
	void clearTextEdit();
	void setCurrentFile(const QString &fileName);
	bool okToContinue();
};

#endif // NOTECLIENT_H
