/**
* @file apilib.h
* @brief 定義はアセンブラで記述されています
* @details hrb_api()でAPIの識別と処理を行っています
*/

/**
* @brief
* 一文字表示する
* @param c ASCII文字コード
*/
void api_putchar(int c);

/**
* @brief
* 文字列表示する
* @param s 文字列
*/
void api_putstr0(char *s);

/**
* @brief 
* 文字列sの先頭からl字だけ表示する
* @param s 文字列
* @param l 表示する文字数
*/
void api_putstr1(char *s, int l);

/**
* @brief 終了API
* @note APIが0以外を返す場合アプリを強制終了する
*/
void api_end(void);

/**
 * @brief 
 * ウインドウを生成する
 * @param buf ウインドウのバッファ
 * @param xsiz x方向の大きさ
 * @param ysiz y方向の大きさ
 * @param col_inv 透明にする色
 * @param title ウインドウタイトル
 * @return int ウインドウID
 */
int api_openwin(char *buf, int xsiz, int ysiz, int col_inv, char *title);

/**
 * @brief 
 * 指定ウインドウに文字列を表示する
 * @param win ウインドウID
 * @param x 文字列表示位置x
 * @param y 文字列表示位置y
 * @param col 文字色
 * @param len 文字列の長さ
 * @param str 文字列
 */
void api_putstrwin(int win, int x, int y, int col, int len, char *str);

/**
 * @brief 
 * 指定ウインドウに四角形を描画する
 * @param win ウインドウID
 * @param x0 始点x
 * @param y0 始点y
 * @param x1 終点x
 * @param y1 終点y
 * @param col 色
 */
void api_boxfilwin(int win, int x0, int y0, int x1, int y1, int col);

/**
 * @brief 
 * メモリマネージャの初期化を行う
 */
void api_initmalloc(void);

/**
 * @brief 
 * 指定サイズのメモリを確保する
 * @param size 要求バイト数
 * @return char* 確保したメモリ番地
 */
char *api_malloc(int size);

/**
 * @brief 
 * メモリ開放する
 * @param addr 開放するメモリ番地
 * @param size 開放するバイト数
 */
void api_free(char *addr, int size);

/**
 * @brief 
 * ウインドウに点を打つ
 * @param win ウインドウID
 * @param x 表示x
 * @param y 表示y
 * @param col 色
 */
void api_point(int win, int x, int y, int col);

/**
 * @brief 
 * ウインドウのリフレッシュを行う
 * オートリフレッシュ無効時にはこの関数でマニュアルリフレッシュを行ってください
 * オートリフレッシュ無効化の方法はウインドウIDをインクリメントしてください
 * @param win ウインドウID
 * @param x0 始点x
 * @param y0 始点y
 * @param x1 終点x
 * @param y1 終点y
 */
void api_refreshwin(int win, int x0, int y0, int x1, int y1);

/**
 * @brief 
 * ウインドウに線を引きます
 * @param win ウインドウID
 * @param x0 始点x
 * @param y0 始点y
 * @param x1 終点x
 * @param y1 終点y
 * @param col 色
 */
void api_linewin(int win, int x0, int y0, int x1, int y1, int col);

/**
 * @brief 
 * ウインドウを閉じます
 * @param win ウインドウID
 */
void api_closewin(int win);

/**
 * @brief 
 * キー入力を受け付けます
 * @param mode 
 * 0:キー入力が無ければ-1を返し,スリープは行いません
 * 1:キー入力があるまでスリープします
 * @return int 入力された文字コード
 */
int api_getkey(int mode);

/**
 * @brief 
 * タイマを取得します
 * @return int タイマID
 */
int api_alloctimer(void);

/**
 * @brief 
 * タイマの送信データ設定を行います
 * タイムアウト時に送信データを送信します
 * @param timer タイマID
 * @param data 送信データ
 */
void api_inittimer(int timer, int data);

/**
 * @brief 
 * タイマの発火時間を設定します
 * @param timer タイマID
 * @param time 発火時間[100=1sec]
 */
void api_settimer(int timer, int time);

/**
 * @brief 
 * タイマを開放します
 * @param timer タイマID
 */
void api_freetimer(int timer);

/**
 * @brief 
 * BEEPサウンドを使用して音を鳴らします
 * QEMUにはBEEPサウンドエミュレーション機能はないことに注意してください
 * PITクロックは1.19318[MHz]を前提としています
 * @param tone 周波数[mHz],0を指定するとミュートになります
 */
void api_beep(int tone);

/**
 * @brief 
 * ファイルをオープンします
 * @param fname ファイル名
 * @return int ファイルハンドル
 */
int api_fopen(char *fname);

/**
 * @brief 
 * ファイルをクローズします
 * @param fhandle ファイルハンドル
 */
void api_fclose(int fhandle);

/**
 * @brief 
 * ファイルをシークします
 * @param fhandle ファイルハンドル
 * @param offset シーク量
 * @param mode 
 * シークモード
 * 0:シーク原点をファイル先頭にセット
 * 1:シーク原点を現在のアクセス位置にセット
 * 2:シーク原点をファイルの終端にセット
 */
void api_fseek(int fhandle, int offset, int mode);

/**
 * @brief 
 * ファイルサイズを取得します
 * @param fhandle ファイルハンドル
 * @param mode 
 * ファイルサイズ取得モード
 * 0:一般ファイルサイズ
 * 1:現在の読み込み位置がファイル先頭から何バイト目か
 * 2:ファイル終端からみた現在位置までのバイト数
 * @return int ファイルサイズ
 */
int api_fsize(int fhandle, int mode);

/**
 * @brief 
 * ファイルを読み込みます
 * @param buf バッファ番地
 * @param maxsize 最大読み込むバイト数
 * @param fhandle ファイルハンドル
 * @return int 今回読み込んだバイト数
 */
int api_fread(char *buf, int maxsize, int fhandle);

/**
 * @brief 
 * コマンドラインの取得を行います
 * @param buf コマンドライン格納番地
 * @param maxsize 何バイトまで格納できるか
 * @return int 格納したバイト数
 */
int api_cmdline(char *buf, int maxsize);

/**
 * @brief 
 * 現在の言語モードを表示します
 * @return int 
 * 0:English ASCII
 * 1:Japanese Shift-JIS
 * 2:Japanese EUC
 */
int api_getlang(void);

/**
 * @brief 
 * ボーダレスウインドウを生成する
 * @param buf ウインドウのバッファ
 * @param xsiz x方向の大きさ
 * @param ysiz y方向の大きさ
 * @param col_inv 透明にする色
 * @param title ウインドウタイトル
 * @return int ウインドウID
 */
int api_openBorderlessWin(char *buf, int xsize, int ysize, int col_inv, char *title);