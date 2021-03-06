//
//  INTableViewCell.h
//  INTableView
//
//  Created by Allan Barbato on 9/7/11.
//  Copyright 2011 Allan Barbato. All rights reserved.
//

#import <UIKit/UIKit.h>

@class INTableView;

#define DEFAULT_CELL_HEIGHT 44.0

@interface INTableViewCell : UITableViewCell

@property (nonatomic, readonly, getter = isFromTableView) INTableView* fromTableView;

@property (nonatomic, assign) CGFloat       cellHeight;
@property (nonatomic, retain) NSIndexPath*  indexPath;
@property (nonatomic, retain) NSString*     slideToDeleteText;
@property (nonatomic, retain) NSString*     cellTag;

@property (nonatomic, readonly, getter = canSlideToDelete) BOOL slideToDelete;
@property (nonatomic, getter = canBeSelected, setter = setSelectable:) BOOL isSelectable;

@property (nonatomic, copy) void            (^selectBlock)(INTableViewCell* cell);
@property (nonatomic, copy) void            (^accessoryBlock)(INTableViewCell* cell);
@property (nonatomic, copy) void            (^deleteBlock)(INTableViewCell* cell);

// You can init with the selected block already set
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier selectBlock:(void (^)(INTableViewCell*))block;

- (id)cellWithTag:(NSString*)tag;

// Allow you to activate the action when you slide right to the cell and it bring the red button that say "Delete"
// Then assign an action that will be called when the animation of deleting the cell is finished
// A call to the server to say that the user removed an object, for exemple
- (void)slideToDeleteActivated:(BOOL)activated deleteBlock:(void (^)(INTableViewCell*))block;

// Same method where you can also change the "Delete" label to whatever you need
// You can also set the 'slideToDeleteText' var
- (void)slideToDeleteActivated:(BOOL)activated withDeleteText:(NSString*)deleteText deleteBlock:(void (^)(INTableViewCell*))block;

- (void)belongToTableView:(INTableView*)tableView;

//
//  Cells
//
// /!\ Caution /!\
// All of the following methods returns autoreleased INTableViewCell
// Don't forget to retain it, if you want to use it later
//

// A basic cell with only a title
+ (INTableViewCell*)defaultCellWithTitle:(NSString*)title selectBlock:(void (^)(INTableViewCell*))block;

// A basic cell with only a title and a detail text at the right of the cell
+ (INTableViewCell*)defaultCellWithTitle:(NSString*)title detailText:(NSString*)detail selectBlock:(void (^)(INTableViewCell*))block;

// A basic cell with only a title and a subtitle text at the bottom of the cell
+ (INTableViewCell*)subtitledCellWithTitle:(NSString*)title subtitleText:(NSString*)sub selectBlock:(void (^)(INTableViewCell*))block;

// A basic cell with only a title. But centered and colored in blue
+ (INTableViewCell*)actionCellWithTitle:(NSString*)title selectBlock:(void (^)(INTableViewCell*))block;

// A cell with a title a subtitle and a small arrow at the right
+ (INTableViewCell*)pushCellWithTitle:(NSString*)title subtitleText:(NSString*)sub selectBlock:(void (^)(INTableViewCell*))block;

// A cell with a title a subtitle and the imageView of the cell set with the image name
+ (INTableViewCell*)imageCellWithImage:(UIImage*)image title:(NSString*)title detailText:(NSString*)detail selectBlock:(void (^)(INTableViewCell*))block;

@end
