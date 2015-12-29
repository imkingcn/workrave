// Copyright (C) 2002 - 2015 Rob Caelers & Raymond Penners
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef STATISTICSDIALOG_HH
#define STATISTICSDIALOG_HH

#include <QtGui>
#include <QtWidgets>

#include <sstream>

#include "core/IStatistics.hh"
using namespace workrave;

class StatisticsDialog : public QDialog
{
  Q_OBJECT

public:
  StatisticsDialog();

  static const int BREAK_STATS = 7;

  int run();

private:
  IStatistics::Ptr statistics;

  QLabel *break_labels[workrave::BREAK_ID_SIZEOF][9];
  QLabel *activity_labels[5];
  QLabel *usage_label;
  QLabel *daily_usage_time_label;
  QLabel *weekly_usage_time_label;
  QLabel *monthly_usage_time_label;
  QLabel *date_label;

  QCalendarWidget *calendar;
  QPushButton *forward_button;
  QPushButton *back_button;
  QPushButton *last_button;
  QPushButton *first_button;
  QPushButton *delete_button;

  bool update_usage_real_time;
  
  void on_history_delete_all();

  void init_gui();
  void select_day(int day);

  void create_navigation_box(QLayout *parent);
  void create_statistics_box(QLayout *parent);
  
  void create_break_page(QBoxLayout *parent);
  //  void create_activity_page(QWidget *tnotebook);

  void stream_distance(std::stringstream &stream, int64_t pixels);
  void get_calendar_day_index(int &idx, int &next, int &prev);
  void set_calendar_day_index(int idx);
  void on_calendar_month_changed(int year, int month);
  void on_calendar_day_selected(const QDate &date);
  void on_history_go_back();
  void on_history_go_forward();
  void on_history_goto_last();
  void on_history_goto_first();
  void display_calendar_date();
  void display_statistics(IStatistics::DailyStats *stats);
  void clear_display_statistics();
  void display_week_statistics();
  void display_month_statistics();
  bool on_timer();
};

#endif // STATISTICSDIALOG_HH
