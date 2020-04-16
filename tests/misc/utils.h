#ifndef VIFM_TESTS__UTILS_H__
#define VIFM_TESTS__UTILS_H__

/* Executable suffixes. */
#if defined(__CYGWIN__) || defined(_WIN32)
#define EXE_SUFFIX ".exe"
#define EXE_SUFFIXW L".exe"
#else
#define EXE_SUFFIX ""
#define EXE_SUFFIXW L""
#endif

#ifdef _WIN32
#define SL "\\\\"
#else
#define SL "/"
#endif

struct view_t;

/* Prepares configuration for use in tests. */
void conf_setup(void);

/* Cleans up configuration. */
void conf_teardown(void);

/* Prepares option handler for use in tests. */
void opt_handlers_setup(void);

/* Cleans up option handlers. */
void opt_handlers_teardown(void);

/* Prepares undo unit for file operations. */
void undo_setup(void);

/* Cleans up undo unit. */
void undo_teardown(void);

/* Initializes view with safe defaults. */
void view_setup(struct view_t *view);

/* Frees resources of the view. */
void view_teardown(struct view_t *view);

/* Registers a column with specified id that prints empty string. */
void columns_setup_column(int id);

/* Unregisters all columns and resets print function. */
void columns_teardown(void);

/* Creates file at the path. */
void create_file(const char path[]);

/* Creates executable file at the path. */
void create_executable(const char path[]);

/* Either puts base/sub or cwd/base/sub into the buf.  If cwd is NULL, current
 * working directory is used. */
void make_abs_path(char buf[], size_t buf_len, const char base[],
		const char sub[], const char cwd[]);

/* Copies file at src to dst. */
void copy_file(const char src[], const char dst[]);

/* Whether running on non-Windows.  Returns non-zero if so, otherwise zero is
 * returned. */
int not_windows(void);

/* Attempts to switch to UTF-8 capable locale.  Use utf8_locale() to check if
 * successful. */
void try_enable_utf8_locale(void);

/* Whether locale is UTF-8.  Returns non-zero if so, otherwise zero is
 * returned. */
int utf8_locale(void);

struct matcher_t;

/* Changes *matcher to have the value of the expr.  The operation is assumed to
 * succeed, but it's not guaranteed. */
int replace_matcher(struct matcher_t **matcher, const char expr[]);

struct view_t;

/* Setups a grid of specified dimentions for the view. */
void setup_grid(struct view_t *view, int column_count, int list_rows, int init);

/* Setups transposed grid of specified dimentions for the view. */
void setup_transposed_grid(struct view_t *view, int column_count, int list_rows,
		int init);

/* Loads dummy list of files into a view.  It consists of a single fake
 * entry. */
void init_view_list(struct view_t *view);

/* Waits termination of all background tasks. */
void wait_for_bg(void);

/* Verifies that file at specified path consists of specified list of lines. */
void file_is(const char path[], const char *lines[], int nlines);

/* Replaces value of an environment variable.  Pass returned value to
 * unmock_env() to restore its state.  Returns its old value. */
char * mock_env(const char env[], const char with[]);

/* Restores value of an environment variable changed by mock_env(). */
void unmock_env(const char env[], char old_value[]);

#endif /* VIFM_TESTS__UTILS_H__ */

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 filetype=c : */
