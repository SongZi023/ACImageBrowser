//
//  ACImageBrowser.h
//
//  Created by Albert Chu on 14/8/11.
//

#import <UIKit/UIKit.h>


@protocol ACImageBrowserDelegate <NSObject>
- (void)dismissAtIndex:(NSInteger)index;
@end


@interface ACImageBrowser : UIViewController

@property (nonatomic, assign) id<ACImageBrowserDelegate>    delegate;

@property (nonatomic, assign) BOOL                          fullscreenEnable;


- (id)initWithImagesURLArray:(NSMutableArray *)imagesURLArray;

- (void)setPageIndex:(NSUInteger)index;

//** for custom subclass working with things like bottom toolbar ***************************
// default animation duration is ACIBU_BGColor_AnimationDuration (0.28f)
- (void)willAnimateToFullscreenMode;
- (void)willAnimateToNormalMode;
//****************************************************************************************//


//** for deleting cell *********************************************************************
@property (nonatomic, retain) UICollectionView              *collectionView;
@property (nonatomic, retain) NSMutableArray                *imagesURLArray;

- (void)updateTitleText;
//****************************************************************************************//


//** readonly ******************************************************************************
@property (nonatomic, assign, readonly) BOOL                isRoating;

@property (nonatomic, assign, readonly) NSInteger           currentPage;
@property (nonatomic, assign, readonly) BOOL                isFullscreen;
//****************************************************************************************//

@end
