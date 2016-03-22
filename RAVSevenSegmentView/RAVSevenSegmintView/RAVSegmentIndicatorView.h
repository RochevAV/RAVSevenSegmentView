//
//  RAVSegmentIndicatorView.h
//  RAVSevenSegmentView
//
//  Created by Aleksey Rochev on 18.03.16.
//  Copyright © 2016 Aleksey Rochev. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM (NSInteger, RAVSegmentIndicatorViewFontType) {
    RAVSegmentIndicatorViewFontCondensed,
    RAVSegmentIndicatorViewFontPlump
};

#pragma mark -

IB_DESIGNABLE

@interface RAVSegmentIndicatorView : UIView <NSCopying>
/**
 *@brief Тип шрифта
 *@note по заданию реализовано только два типа: вытянутый (Condensed) и пухлый (Plump)
 *
 */
@property RAVSegmentIndicatorViewFontType typeFont;

/**
 *@brief Цвет подсветки сегментов индикатора
 *@note При установке цвета, сбрасывается анимация
 *@warning НЕ НАДО ПОСТОЯННО УСТАНАВЛИВАТЬ ЦВЕТ!
 *
 */
@property (nonatomic, copy) IBInspectable UIColor *colorActive;
/**
 *@brief Цвет сегментов индикатора по умолчанию (фон)
 *@note При установке цвета, сбрасывается анимация
 *@warning НЕ НАДО ПОСТОЯННО УСТАНАВЛИВАТЬ ЦВЕТ!
 *
 */
@property (nonatomic, copy) IBInspectable UIColor *colorDefault;
/**
 *@brief Значение
 *@note При установке значения запускается анимация, если свойство animation == YES
 *
 */
@property (nonatomic) NSInteger value;
/**
 *@brief Код - двоичное число
 *@note Последовательность 0 и 1, номеру по порядку соответствует сегмент, если установлен в еденицу значит сегмент горит. При установке значения запускается анимация, если свойство animation == YES
 *
 */
@property (nonatomic) NSInteger codeIndicator;
/**
 *@brief анимация
 *@note  Наличие анимации при смене значения индикатора
 *
 */
@property (nonatomic) IBInspectable BOOL animation;
/**
 *@brief Продолжительность анимации
 *@note  Продолжительность анимации смены значения индикатора
 *
 */
@property (nonatomic) IBInspectable NSTimeInterval animationDuration;
/*!
 *@brief Массив слоев, из которых состоит индикатор
 *@brief Используется для добавления анимации при изменении значения индикатора
 */
@property (nonatomic, readonly) NSDictionary *layers;
/**
 *@brief Число является еденицей
 *@note  Тысячи, сотни, десятки, еденицы - в этом контектсе. Будет стоять точка после цифры
 *
 */
@property (nonatomic, getter=isOne) IBInspectable BOOL one;
/**
 *@brief Индикатор выключен
 *@note  Работает аналогично методу clearAllSegments
 *
 */
@property (nonatomic, getter=isOff) BOOL off;
/**
 *@brief Все сегменты переводятся в неактивное состояние
 *
 */
- (void) clearAllSegments;
/**
 *@brief Все сегменты переводятся в активное состояние
 *
 */
- (void) setAllSegments;

@end

#pragma mark -

@interface RAVSegmentIndicatorView (Alphabet)

+ (NSInteger) codeWithInteger:(NSInteger)value;

+ (NSInteger) codeWithChar:(char)value;
+ (NSInteger) codeWithString:(NSString *)value;

+ (NSInteger) codeForClearSegments;
+ (NSInteger) codeForSetAllSegments;

@end

#pragma mark -

@interface RAVSegmentIndicatorView (Paint)

+ (NSArray<UIBezierPath *> *) arrBezierSegmentsWithType: (RAVSegmentIndicatorViewFontType) type;
+ (NSArray<UIBezierPath *> *) arrLayerSegmentsWithType: (RAVSegmentIndicatorViewFontType) type;

+ (CAShapeLayer*) layerBackgroundWithRect:(CGRect) rect withType: (RAVSegmentIndicatorViewFontType) type;

@end

#pragma mark -

@interface RAVSegmentIndicatorView (Animation)

+ (CABasicAnimation*) transformAnimationFromAngle: (CGFloat) fromAngle
                                          toAngle:(CGFloat) toAngle
                                         duration:(CGFloat) duration;

+ (CAKeyframeAnimation*) fillColorAnimationFromColor: (UIColor *) fromColor
                                             toColor: (UIColor *) toColor
                                            duration:(CGFloat) duration;

@end