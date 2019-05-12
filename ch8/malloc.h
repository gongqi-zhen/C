typedef long Align; /* longの境界に整合させる */

union header { /* ブロックのヘッダ */
	struct {
		union header *ptr; /* 空きリストの上なら次のブロック */
		unsigned size; /* このブロックの大きさ */
	} s;
	Align x;  /* ブロックの整合を統制 */
};

typedef union header Header;
