#include "ExampleWindow.h"

#include <stdexcept>
#include <SDL2/SDL_image.h>

ExampleWindow::ExampleWindow(int width, int height) :
		Window(width, height),
				_width_cloud(width / 5), _width_sun(width/2),
				_sky_x(0), _sky_x2(width),
				_sun_x(width), _sun_y(-height/15),
				_cloud_x_up(width), _cloud_x_up2(width + _width_cloud), _cloud_x_up3(width + _width_cloud *2),
				_cloud_x_up4(width + _width_cloud *3), _cloud_x_up5(width + _width_cloud * 4), _cloud_x_up6(width + _width_cloud * 5),
				_sky_y(0), _grass_y(height / 2 + height / 10), _mountes_y(height / 10), _cloud_y(height / 90),
				_step_slow(1), _step_cloud(3), _step_sun(2), _step_fast(4), _step_tree(2),
				_road_x(0), _road_x2(width), _road_y(height/5*3.2),
				_car_x(0), _car_y((height/5*3.2)-height/16), _tree_x(width/15), _tree_x2(width*12/15), _tree_y(height/9),
				_column_x(width/20), _column_x2(width/20*5), _column_x3(width/20*10), _column_x4(width/20*15),
				_column_x1(width/20 + 50), _column_x12(width/20*5 + 50), _column_x13(width/20*10 + 50), _column_x14(width/20*15 + 50),
				_column_y(height/50*27), _column_y1(height/50*36),
				_sign_x(width/14), _sign_y(height/50*22),
				_stone_x(width/8), _stone_x2(width/8*7), _stone_y(height/50*36){
	_sky = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sky2.png"), SDL_DestroyTexture);
	if (_sky == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить небо: ")
						+ std::string(SDL_GetError()));
	_grass = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "grass3.png"), SDL_DestroyTexture);
	if (_grass == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить траву: ")
						+ std::string(SDL_GetError()));
	_mountes = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "mountes.png"),
			SDL_DestroyTexture);
	if (_mountes == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить горы: ")
						+ std::string(SDL_GetError()));
	_cloud = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud.png"), SDL_DestroyTexture);
	_cloud2 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud2.png"), SDL_DestroyTexture);
	if (_cloud == nullptr || _cloud2 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить облака: ")
						+ std::string(SDL_GetError()));
	_sun = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sun.png"),
			SDL_DestroyTexture);
	if (_sun == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить солнце: ")
						+ std::string(SDL_GetError()));
	_road = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "road.png"),
			SDL_DestroyTexture);
	if (_road == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить дорогу: ")
						+ std::string(SDL_GetError()));
	_car = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "car.png"),
			SDL_DestroyTexture);
	if (_car == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить машину: ")
						+ std::string(SDL_GetError()));
	_tree = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "tree.png"),
			SDL_DestroyTexture);
	if (_tree == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить дерево: ")
						+ std::string(SDL_GetError()));
	_column = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "column.png"),
			SDL_DestroyTexture);
	if (_column == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить столбики: ")
						+ std::string(SDL_GetError()));
	_sign = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sign.png"),
			SDL_DestroyTexture);
	if (_sign == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить знак: ")
						+ std::string(SDL_GetError()));
	_stone = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "stone.png"),
			SDL_DestroyTexture);
	if (_stone == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить булыжниг: ")
						+ std::string(SDL_GetError()));
}

void ExampleWindow::render() {
	SDL_SetRenderDrawColor(_renderer.get(), 32, 32, 96, 255);
	SDL_RenderClear(_renderer.get());

	SDL_Rect sky_rect { _sky_x, _sky_y, width(), (height() / 2 + height() / 10) };
	SDL_Rect sky_rect2 { _sky_x2, _sky_y, width(),
			(height() / 2 + height() / 10) };
	SDL_Rect grass_rect { _sky_x, _grass_y, width(), height() / 2 };
	SDL_Rect grass_rect2 { _sky_x2, _grass_y, width(), height() / 2 };
	SDL_Rect mountes_rect { _sky_x, _mountes_y, width(), height() / 2 };
	SDL_Rect mountes_rect2 { _sky_x2, _mountes_y, width(), height() / 2 };
	SDL_Rect cloud_rect { _cloud_x_up, _cloud_y + 50, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect2 { _cloud_x_up2, _cloud_y + 180, _width_cloud, height()
				/ 7 };
	SDL_Rect cloud_rect3 { _cloud_x_up3, _cloud_y + 50, _width_cloud, height()
				/ 7 };
	SDL_Rect cloud_rect4 { _cloud_x_up4, _cloud_y + 180, _width_cloud, height()
				/ 7 };
	SDL_Rect cloud_rect5 { _cloud_x_up5, _cloud_y + 50, _width_cloud, height()
				/ 7 };
	SDL_Rect cloud_rect6 { _cloud_x_up6, _cloud_y + 180, _width_cloud, height()
				/ 7 };
	SDL_Rect sun_rect{ _sun_x, _sun_y, _width_sun, _width_sun};
	SDL_Rect road_rect{ _road_x, _road_y, width(), height()/5};
	SDL_Rect road_rect2{ _road_x2, _road_y, width(), height()/5};
	SDL_Rect car_rect{ _car_x, _car_y, width()/4, height()/8};
	SDL_Rect tree_rect{ _tree_x, _tree_y, width()/3, height()/2};
	SDL_Rect tree_rect2{ _tree_x2, _tree_y, width()/3, height()/2};
	SDL_Rect column_rect{ _column_x, _column_y, width()/16, height()/8};
	SDL_Rect column_rect2{ _column_x2, _column_y, width()/16, height()/8};
	SDL_Rect column_rect3{ _column_x3, _column_y, width()/16, height()/8};
	SDL_Rect column_rect4{ _column_x4, _column_y, width()/16, height()/8};
	SDL_Rect column_rect1{ _column_x1, _column_y1, width()/16, height()/8};
	SDL_Rect column_rect12{ _column_x12, _column_y1, width()/16, height()/8};
	SDL_Rect column_rect13{ _column_x13, _column_y1, width()/16, height()/8};
	SDL_Rect column_rect14{ _column_x14, _column_y1, width()/16, height()/8};
	SDL_Rect sign_rect{ _sign_x, _sign_y, width()/5, height()/2};
	SDL_Rect stone_rect{ _stone_x, _stone_y, width()/4, height()/4};
	SDL_Rect stone_rect2{ _stone_x2, _stone_y, width()/4, height()/4};


	SDL_RenderCopy(_renderer.get(), _sky.get(), nullptr, &sky_rect);
	SDL_RenderCopyEx(_renderer.get(), _sky.get(), nullptr, &sky_rect2, 0,
			nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _grass.get(), nullptr, &grass_rect);
	SDL_RenderCopy(_renderer.get(), _grass.get(), nullptr, &grass_rect2);
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud_rect2);
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud_rect4);
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud_rect6);
	SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun_rect);
	SDL_RenderCopy(_renderer.get(), _mountes.get(), nullptr, &mountes_rect);
	SDL_RenderCopyEx(_renderer.get(), _mountes.get(), nullptr, &mountes_rect2,
			0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect5);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect3);
	SDL_RenderCopy(_renderer.get(), _road.get(), nullptr, &road_rect);
	SDL_RenderCopyEx(_renderer.get(), _road.get(), nullptr, &road_rect2,
			0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree_rect);
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree_rect2);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect2);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect3);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect4);
	SDL_RenderCopy(_renderer.get(), _car.get(), nullptr, &car_rect);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect1);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect12);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect13);
	SDL_RenderCopy(_renderer.get(), _column.get(), nullptr, &column_rect14);
	SDL_RenderCopy(_renderer.get(), _sign.get(), nullptr, &sign_rect);
	SDL_RenderCopy(_renderer.get(), _stone.get(), nullptr, &stone_rect);
	SDL_RenderCopy(_renderer.get(), _stone.get(), nullptr, &stone_rect2);

}

void ExampleWindow::do_logic() {
	_sky_x -= _step_slow;
	_sky_x2 -= _step_slow;
	_cloud_x_up -= _step_cloud;
	_cloud_x_up2 -= _step_cloud;
	_cloud_x_up3 -= _step_cloud;
	_cloud_x_up4 -= _step_cloud;
	_cloud_x_up5 -= _step_cloud;
	_cloud_x_up6 -= _step_cloud;
	_sun_x -= _step_sun;
	_road_x -= _step_slow;
	_road_x2 -= _step_slow;
	_car_x += _step_fast;
	_tree_x -= _step_tree;
	_tree_x2 -= _step_tree;
	_column_x -= _step_fast;
	_column_x2 -= _step_fast;
	_column_x3 -= _step_fast;
	_column_x4 -= _step_fast;
	_column_x1 -= _step_fast;
	_column_x12 -= _step_fast;
	_column_x13 -= _step_fast;
	_column_x14 -= _step_fast;
	_sign_x -= _step_fast;
	_stone_x -= _step_fast;
	_stone_x2 -= _step_fast;
	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_cloud_x_up <= -_width_cloud) {
		_cloud_x_up = width();
	}
	if (_cloud_x_up2 <= -_width_cloud) {
		_cloud_x_up2 = width();
	}
	if (_cloud_x_up3 <= -_width_cloud) {
		_cloud_x_up3 = width();
	}
	if (_cloud_x_up4 <= -_width_cloud) {
		_cloud_x_up4 = width();
	}
	if (_cloud_x_up5 <= -_width_cloud) {
		_cloud_x_up5 = width();
	}
	if (_cloud_x_up6 <= -_width_cloud) {
		_cloud_x_up6 = width();
	}
	if (_sun_x <= 0-_width_sun) {
		_sun_x = width();
	}
	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_road_x <= 0 - width()) {
		_road_x = width();
	}
	if (_road_x2 <= 0 - width()) {
		_road_x2 = width();
	}
	if (_car_x > width()) {
		_car_x = -width()/4;
	}
	if (_tree_x <= 0 - width()/3) {
		_tree_x = width();
	}
	if (_tree_x2 <= 0 - width()/3) {
		_tree_x2 = width();
	}
	if (_column_x <= 0 - width()/16) {
		_column_x = width();
	}
	if (_column_x2 <= 0 - width()/16) {
		_column_x2 = width();
	}
	if (_column_x3 <= 0 - width()/16) {
		_column_x3 = width();
	}
	if (_column_x4 <= 0 - width()/16) {
		_column_x4 = width();
	}
	if (_column_x1 <= 0 - width()/16) {
		_column_x1 = width();
	}
	if (_column_x12 <= 0 - width()/16) {
		_column_x12 = width();
	}
	if (_column_x13 <= 0 - width()/16) {
		_column_x13 = width();
	}
	if (_column_x14 <= 0 - width()/16) {
		_column_x14 = width();
	}
	if (_sign_x <= 0 - width()/5*3) {
		_sign_x = width();
	}
	if (_stone_x <= 0 - width()/3) {
		_stone_x = width();
	}
	if (_stone_x2 <= 0 - width()/3) {
		_stone_x2 = width();
	}
}

void ExampleWindow::handle_keys(const Uint8 *keys) {
	if (keys[SDL_SCANCODE_DOWN] && _car_y < (_road_y + (height()/5)/3))
		_car_y += 4;
	if (keys[SDL_SCANCODE_UP] && _car_y > (height()/5*3.2)-height()/16)
		_car_y -= 4;
}
