#ifndef __TRIVIALDB_TABLE_HEADER__
#define __TRIVIALDB_TABLE_HEADER__
#include "../defs.h"
#include <stdint.h>

struct table_header_t
{
	// the number of columns (fixed and variant)
	uint8_t col_num;
	// main index for this table
	uint8_t main_index, is_main_index_additional;

	int records_num;
	uint32_t flag_notnull, flag_primary, flag_indexed;
	uint8_t col_type[MAX_COL_NUM];

	// the length of columns
	int col_length[MAX_COL_NUM];
	// the offset of columns
	int col_offset[MAX_COL_NUM];
	// root page of index, 0 if no index
	int index_root[MAX_COL_NUM];
	// auto increment counter
	int64_t auto_inc;

	char col_name[MAX_COL_NUM][MAX_NAME_LEN];
	char table_name[MAX_NAME_LEN];
};

#endif