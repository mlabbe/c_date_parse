/*
  date_parse is lifted from the GPLv2 release of Git
  and is Copyright (C) Linus Torvalds, 2005
*/

#ifndef DATE_PARSE_H
#define DATE_PARSE_H


/* disabled bits of code from date.c because they do things not necessary for date
   parsing and pull in other parts of the git code.  Left intact for merge management. */
#define DATE_PARSE_ENABLE 0

struct timeval;

struct date_mode {
	enum date_mode_type {
		DATE_NORMAL = 0,
		DATE_RELATIVE,
		DATE_SHORT,
		DATE_ISO8601,
		DATE_ISO8601_STRICT,
		DATE_RFC2822,
		DATE_STRFTIME,
		DATE_RAW
	} type;
	const char *strftime_fmt;
	int local;
};


/*
 * Convenience helper for passing a constant type, like:
 *
 *   show_date(t, tz, DATE_MODE(NORMAL));
 */
#define DATE_MODE(t) date_mode_from_type(DATE_##t)

struct date_mode *date_mode_from_type(enum date_mode_type type);

const char *show_date(unsigned long time, int timezone, const struct date_mode *mode);
int parse_date_basic(const char *date, unsigned long *timestamp, int *offset);
int parse_expiry_date(const char *date, unsigned long *timestamp);
#define approxidate(s) approxidate_careful((s), NULL)
unsigned long approxidate_careful(const char *, int *);
unsigned long approxidate_relative(const char *date, const struct timeval *now);
void parse_date_format(const char *format, struct date_mode *mode);
int date_overflows(unsigned long date);

int parse_date(const char *date, char *result, int maxlen);

#if DATE_PARSE_ENABLE
void show_date_relative(unsigned long time, int tz, const struct timeval *now,
			struct strbuf *timebuf);
int parse_date(const char *date, struct strbuf *out);
void datestamp(struct strbuf *out);
#endif

#endif
