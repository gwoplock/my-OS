/*
 * PageTable.h
 *
 *  Created on: Mar 2, 2017
 *      Author: garrett
 */

#ifndef PAGETABLE_H_
#define PAGETABLE_H_

#include"../../global.h"

struct PageDirEntry {
		char present :1;
		char read_write :1;
		char user_super :1;
		char writeThrough :1;
		char cache :1;
		char accessed :1;
		char zero :1;
		char size :1;
		char ignored :1;
		char osInfo :3;
		uint32_t pageTableAddr :20;
}__attribute__((__packed__));

struct PageTableEntry {
		char present :1;
		char read_write :1;
		char user_super :1;
		char writeThrough :1;
		char cache :1;
		char accessed :1;
		char dirty :1;
		char zero :1;
		char global :1;
		char osInfo :3;
		uint32_t physicalAddress :20;
}__attribute__((__packed__));

extern uint32_t kernelSize;
extern uint32_t kernelStart;

class PageTable {

	private:
		PageDirEntry pageDir[1024] __attribute__((aligned(4096)));
		PageTableEntry pageTables[1024 * 1024] __attribute__((aligned(4096)));
		static const uint32_t vKernelStart = 0xC0000000;

	public:
		PageTable( );
		PageTable(bool buildFlag);
		/**
		 * resetup paging, set it how I like it
		 */
		void build();
		/**
		 * page in some mem
		 * @param phy Start
		 * @param virt Start
		 * @param size to page
		 * @return the actual start point
		 */
		void* page(void* phyStart, void* virtStart, size_t size);
		/**
		 * asm helper to move the page dir
		 * @param page Dir
		 */
		void movePageTable(PageDirEntry pagedir[1024]);
		/**
		 * @return the vertual kernel start
		 */
		void* getKernelStart(){
			return (void *) vKernelStart;
		}
		/**
		 * get the full page table
		 * @return the page table
		 */
		PageTableEntry* getPageTables(){
			return pageTables;
		}
};

#endif /* PAGETABLE_H_ */
