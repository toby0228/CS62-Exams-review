# Qt GUI Programming: Key Concepts

These notes explain six important concepts in Qt (C++) GUI programming: `QWidget`, `QMainWindow`, `ui`, signals, slots, and `connect()`.

## 1. `QWidget` — Class

`QWidget` is a Qt class that provides the basic building block for graphical user interfaces (GUIs).

Common subclasses of `QWidget` include:

- `QPushButton` — A clickable button.
- `QLabel` — Displays text or an image.
- `QLineEdit` — A single-line text input field.
- `QMainWindow` — A window designed for a main application interface.

**Remember:** `QWidget` is the base for many visible UI elements.

## 2. `QMainWindow` — Class

`QMainWindow` is a subclass of `QWidget` designed to serve as the main window of an application. It provides support for menu bars, toolbars, status bars, and a central widget.

```cpp
class MainWindow : public QMainWindow
{
    // ...
};
```

The `:` indicates **inheritance**: `MainWindow` inherits from `QMainWindow` and can use the functionality it provides.

**Remember:** In a typical Qt Widgets application, your own `MainWindow` class inherits from `QMainWindow`.

## 3. `ui` — Field (Member Variable)

`ui` is commonly a **pointer field** inside the `MainWindow` class. In projects made with Qt Designer, it provides access to widgets defined in the `.ui` file.

```cpp
private:
    Ui::MainWindow *ui;
```

You can use `ui` to access the interface's widgets:

```cpp
ui->pushButton->setText("Click Me");
ui->label->setText("Hello World");
```

- `ui->pushButton` accesses the button named `pushButton`.
- `ui->label` accesses the label named `label`.
- `setText()` changes the widget's displayed text.

**Remember:** `ui` itself is **not a widget**. It is a pointer to an object that helps manage and access the widgets in the interface.

## 4. Signals — Notifications of Events

A **signal** is emitted by a Qt object when something happens. For example, clicking a `QPushButton` emits its `clicked()` signal.

| Widget | Signal | When it is emitted |
|---|---|---|
| `QPushButton` | `clicked()` | The button is clicked. |
| `QLineEdit` | `textChanged()` | The text changes. |
| `QSlider` | `valueChanged()` | The slider's value changes. |

**Remember:** A signal means **“Something happened!”** A signal is not itself a Qt object.

## 5. Slots — Functions That Respond

A **slot** is a function that can be called in response to a signal.

For example:

```cpp
void MainWindow::onButtonClicked()
{
    ui->label->setText("Button clicked!");
}
```

This function changes the label's text. When connected to a button's `clicked()` signal, it runs after the button is clicked.

**Remember:** A slot performs an action in response to a signal. A slot can also be called like a regular function; it does not *only* run after a signal.

## 6. `connect()` — Method

`connect()` links a signal to a slot (or another compatible callable), telling Qt what to run when the signal is emitted.

```cpp
connect(ui->pushButton, &QPushButton::clicked,
        this, &MainWindow::onButtonClicked);
```

| Part | Meaning |
|---|---|
| `ui->pushButton` | The button that sends the signal. |
| `&QPushButton::clicked` | A reference to the button's `clicked` signal. |
| `this` | The current `MainWindow` object that receives the signal. |
| `&MainWindow::onButtonClicked` | The function to call when the signal is emitted. |

**In simple terms:** When `pushButton` is clicked, Qt calls `onButtonClicked()` on the current `MainWindow` object.

## How They Work Together

1. `QMainWindow` provides the application's main window.
2. Widgets such as `QPushButton` and `QLabel` make up the interface.
3. The `ui` field gives your C++ code access to those widgets.
4. The user clicks a button, causing it to emit a `clicked()` **signal**.
5. `connect()` links that signal to `onButtonClicked()`.
6. The **slot** runs and changes the label's text.

### Quick Reference

| Term | Type | Main purpose |
|---|---|---|
| `QWidget` | Class | Basic GUI component. |
| `QMainWindow` | Class | Main application window. |
| `ui` | Field / pointer | Access widgets created through Qt Designer. |
| Signal | Qt notification | Announces that an event occurred. |
| Slot | Function | Responds to a signal. |
| `connect()` | Method | Links a signal to a slot or another callable. |

**Key idea:** **Signal = what happened → `connect()` = how it's linked → Slot = what happens next.**
