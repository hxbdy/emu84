/**
* @file apilib.h
* @brief ��`�̓A�Z���u���ŋL�q����Ă��܂�
* @details hrb_api()��API�̎��ʂƏ������s���Ă��܂�
*/

/**
* @brief
* �ꕶ���\������
* @param c ASCII�����R�[�h
*/
void api_putchar(int c);

/**
* @brief
* ������\������
* @param s ������
*/
void api_putstr0(char *s);

/**
* @brief 
* ������s�̐擪����l�������\������
* @param s ������
* @param l �\�����镶����
*/
void api_putstr1(char *s, int l);

/**
* @brief �I��API
* @note API��0�ȊO��Ԃ��ꍇ�A�v���������I������
*/
void api_end(void);

/**
 * @brief 
 * �E�C���h�E�𐶐�����
 * @param buf �E�C���h�E�̃o�b�t�@
 * @param xsiz x�����̑傫��
 * @param ysiz y�����̑傫��
 * @param col_inv �����ɂ���F
 * @param title �E�C���h�E�^�C�g��
 * @return int �E�C���h�EID
 */
int api_openwin(char *buf, int xsiz, int ysiz, int col_inv, char *title);

/**
 * @brief 
 * �w��E�C���h�E�ɕ������\������
 * @param win �E�C���h�EID
 * @param x ������\���ʒux
 * @param y ������\���ʒuy
 * @param col �����F
 * @param len ������̒���
 * @param str ������
 */
void api_putstrwin(int win, int x, int y, int col, int len, char *str);

/**
 * @brief 
 * �w��E�C���h�E�Ɏl�p�`��`�悷��
 * @param win �E�C���h�EID
 * @param x0 �n�_x
 * @param y0 �n�_y
 * @param x1 �I�_x
 * @param y1 �I�_y
 * @param col �F
 */
void api_boxfilwin(int win, int x0, int y0, int x1, int y1, int col);

/**
 * @brief 
 * �������}�l�[�W���̏��������s��
 */
void api_initmalloc(void);

/**
 * @brief 
 * �w��T�C�Y�̃��������m�ۂ���
 * @param size �v���o�C�g��
 * @return char* �m�ۂ����������Ԓn
 */
char *api_malloc(int size);

/**
 * @brief 
 * �������J������
 * @param addr �J�����郁�����Ԓn
 * @param size �J������o�C�g��
 */
void api_free(char *addr, int size);

/**
 * @brief 
 * �E�C���h�E�ɓ_��ł�
 * @param win �E�C���h�EID
 * @param x �\��x
 * @param y �\��y
 * @param col �F
 */
void api_point(int win, int x, int y, int col);

/**
 * @brief 
 * �E�C���h�E�̃��t���b�V�����s��
 * �I�[�g���t���b�V���������ɂ͂��̊֐��Ń}�j���A�����t���b�V�����s���Ă�������
 * �I�[�g���t���b�V���������̕��@�̓E�C���h�EID���C���N�������g���Ă�������
 * @param win �E�C���h�EID
 * @param x0 �n�_x
 * @param y0 �n�_y
 * @param x1 �I�_x
 * @param y1 �I�_y
 */
void api_refreshwin(int win, int x0, int y0, int x1, int y1);

/**
 * @brief 
 * �E�C���h�E�ɐ��������܂�
 * @param win �E�C���h�EID
 * @param x0 �n�_x
 * @param y0 �n�_y
 * @param x1 �I�_x
 * @param y1 �I�_y
 * @param col �F
 */
void api_linewin(int win, int x0, int y0, int x1, int y1, int col);

/**
 * @brief 
 * �E�C���h�E����܂�
 * @param win �E�C���h�EID
 */
void api_closewin(int win);

/**
 * @brief 
 * �L�[���͂��󂯕t���܂�
 * @param mode 
 * 0:�L�[���͂��������-1��Ԃ�,�X���[�v�͍s���܂���
 * 1:�L�[���͂�����܂ŃX���[�v���܂�
 * @return int ���͂��ꂽ�����R�[�h
 */
int api_getkey(int mode);

/**
 * @brief 
 * �^�C�}���擾���܂�
 * @return int �^�C�}ID
 */
int api_alloctimer(void);

/**
 * @brief 
 * �^�C�}�̑��M�f�[�^�ݒ���s���܂�
 * �^�C���A�E�g���ɑ��M�f�[�^�𑗐M���܂�
 * @param timer �^�C�}ID
 * @param data ���M�f�[�^
 */
void api_inittimer(int timer, int data);

/**
 * @brief 
 * �^�C�}�̔��Ύ��Ԃ�ݒ肵�܂�
 * @param timer �^�C�}ID
 * @param time ���Ύ���[100=1sec]
 */
void api_settimer(int timer, int time);

/**
 * @brief 
 * �^�C�}���J�����܂�
 * @param timer �^�C�}ID
 */
void api_freetimer(int timer);

/**
 * @brief 
 * BEEP�T�E���h���g�p���ĉ���炵�܂�
 * QEMU�ɂ�BEEP�T�E���h�G�~�����[�V�����@�\�͂Ȃ����Ƃɒ��ӂ��Ă�������
 * PIT�N���b�N��1.19318[MHz]��O��Ƃ��Ă��܂�
 * @param tone ���g��[mHz],0���w�肷��ƃ~���[�g�ɂȂ�܂�
 */
void api_beep(int tone);

/**
 * @brief 
 * �t�@�C�����I�[�v�����܂�
 * @param fname �t�@�C����
 * @return int �t�@�C���n���h��
 */
int api_fopen(char *fname);

/**
 * @brief 
 * �t�@�C�����N���[�Y���܂�
 * @param fhandle �t�@�C���n���h��
 */
void api_fclose(int fhandle);

/**
 * @brief 
 * �t�@�C�����V�[�N���܂�
 * @param fhandle �t�@�C���n���h��
 * @param offset �V�[�N��
 * @param mode 
 * �V�[�N���[�h
 * 0:�V�[�N���_���t�@�C���擪�ɃZ�b�g
 * 1:�V�[�N���_�����݂̃A�N�Z�X�ʒu�ɃZ�b�g
 * 2:�V�[�N���_���t�@�C���̏I�[�ɃZ�b�g
 */
void api_fseek(int fhandle, int offset, int mode);

/**
 * @brief 
 * �t�@�C���T�C�Y���擾���܂�
 * @param fhandle �t�@�C���n���h��
 * @param mode 
 * �t�@�C���T�C�Y�擾���[�h
 * 0:��ʃt�@�C���T�C�Y
 * 1:���݂̓ǂݍ��݈ʒu���t�@�C���擪���牽�o�C�g�ڂ�
 * 2:�t�@�C���I�[����݂����݈ʒu�܂ł̃o�C�g��
 * @return int �t�@�C���T�C�Y
 */
int api_fsize(int fhandle, int mode);

/**
 * @brief 
 * �t�@�C����ǂݍ��݂܂�
 * @param buf �o�b�t�@�Ԓn
 * @param maxsize �ő�ǂݍ��ރo�C�g��
 * @param fhandle �t�@�C���n���h��
 * @return int ����ǂݍ��񂾃o�C�g��
 */
int api_fread(char *buf, int maxsize, int fhandle);

/**
 * @brief 
 * �R�}���h���C���̎擾���s���܂�
 * @param buf �R�}���h���C���i�[�Ԓn
 * @param maxsize ���o�C�g�܂Ŋi�[�ł��邩
 * @return int �i�[�����o�C�g��
 */
int api_cmdline(char *buf, int maxsize);

/**
 * @brief 
 * ���݂̌��ꃂ�[�h��\�����܂�
 * @return int 
 * 0:English ASCII
 * 1:Japanese Shift-JIS
 * 2:Japanese EUC
 */
int api_getlang(void);

/**
 * @brief 
 * �{�[�_���X�E�C���h�E�𐶐�����
 * @param buf �E�C���h�E�̃o�b�t�@
 * @param xsiz x�����̑傫��
 * @param ysiz y�����̑傫��
 * @param col_inv �����ɂ���F
 * @param title �E�C���h�E�^�C�g��
 * @return int �E�C���h�EID
 */
int api_openBorderlessWin(char *buf, int xsize, int ysize, int col_inv, char *title);